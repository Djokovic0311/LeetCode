class Solution {
public:
    int mod = 1e9 + 7, m, n, K;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size(), K = k;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
        return dfs(0, 0, 0, grid, dp);
    }
    int dfs(int i, int j, int s, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if (i == m || j == n) return 0;
        if (i == m - 1 && j == n - 1) return (((s + grid[i][j]) % K) == 0) ? 1 : 0;
        if (dp[i][j][s] != -1) return dp[i][j][s];
        return dp[i][j][s] = (dfs(i + 1, j, (s + grid[i][j]) % K, grid, dp) + dfs(i, j + 1, (s + grid[i][j]) % K, grid, dp)) % mod;
    }
};
