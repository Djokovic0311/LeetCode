class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i>=grid.size() || i<0 || j<0 || j>=grid[0].size() || grid[i][j]==0) return 0;
        int tmp = grid[i][j];
        int ans = 0;
        grid[i][j] = 0;
        ans = max(ans, dfs(grid, i+1, j));
        ans = max(ans, dfs(grid, i, j+1));
        ans = max(ans, dfs(grid, i-1, j));
        ans = max(ans, dfs(grid, i, j-1));
        grid[i][j] = tmp;
        return ans+tmp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};