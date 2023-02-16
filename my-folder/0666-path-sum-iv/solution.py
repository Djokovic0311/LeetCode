class Solution:
    def pathSum(self, nums: List[int]) -> int:
        """
        construct a tree in an array where 
        left child of ith node is stored at (2*i)th index
        right child of the ith node is stored at (2*i + 1)th index
        Once tree is constructed, do a dfs to get the sum of all paths
        run the dfs in bottom up fashion to get the right answer
        """
        tree = [None for _ in range(20)]
        root_val = nums[0]%10
        tree[1], cur_idx = root_val, 1
        for num in nums:
            depth, position, val = num//100, (num//10)%10, num%10
            tree[2**(depth-1)-1+position] = val
        print(tree)
        self.ans = 0
        def dfs(index, sum_so_far):
            if index >= len(tree) or tree[index] is None:
                return
            # check if tree[index] is leaf node
            if 2*index >= len(tree) or 2*index < len(tree) and tree[2*index] is None and \
             2* index+1 < len(tree) and tree[2*index+1] is None:
                self.ans+=sum_so_far + tree[index]

            dfs(2*index, tree[index] + sum_so_far)
            dfs(2*index+1, tree[index] + sum_so_far)
        dfs(1, 0)
        return self.ans        
