class Solution {
public:
    int m, n;
    vector<vector<int> > dp;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = size(obstacleGrid), n = size(obstacleGrid[0]);
        dp.resize(m, vector<int>(n));
        return solve(obstacleGrid, 0, 0);
    }
    int solve(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= n) return 0;
        if(grid[i][j]) return dp[i][j] = 0;
        if(i == m - 1 && j == n - 1) return 1; 
        if(dp[i][j]) return dp[i][j];
        return dp[i][j] = solve(grid, i+1,j) + solve(grid,i, j+1);
        
    }
};
