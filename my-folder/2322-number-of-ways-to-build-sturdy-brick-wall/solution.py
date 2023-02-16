class Solution:
    def buildWall(self, height: int, width: int, bricks: List[int]) -> int:
        # find all ways to build a line of bricks
        def dfs_comb(bricks_location, cur_length):
            nonlocal combinations
            if cur_length == width:
                combinations.append(bricks_location.copy())
                return
            # go over all bricks
            for i, brick in enumerate(bricks):
                # check if exceed the length
                if cur_length + brick <= width:
                    # cur_length + brick is the next brick location
                    dfs_comb(bricks_location + [cur_length + brick], cur_length + brick)
                    
        # find ways to build a wall
        @cache
        def dfs_rows(row, h):
            if h == height:
                return 1
            cur = 0
            for i in adj[row]:
                cur += dfs_rows(i, h + 1)
            return cur
        
        combinations = []
        
        # find each line's possbile neighbors
        adj = defaultdict(list)
        dfs_comb([],0)
        for i, comb in enumerate(combinations):
            for j, neighbor in enumerate(combinations):
                # check if bricks at the same location
                if len(set(comb[:-1]) & set(neighbor[:-1])) == 0:
                    adj[i].append(j)
        
        ans, mod = 0, int(1e9+7)
        for i in range(len(combinations)):
            ans += dfs_rows(i, 1) % mod
        return ans % mod
