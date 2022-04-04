class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n || !grid[i][j]) return 0;
        grid[i][j]=0;
        return 1+ dfs(i-1,j,grid)+dfs(i,j-1,grid)+dfs(i+1,j,grid) + dfs(i,j+1,grid);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++)
                if (grid[i][j]) ans = max(ans, dfs(i, j, grid));
        return ans;
    }
};
