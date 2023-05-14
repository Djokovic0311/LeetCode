class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Initialize dp array with 0
        vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

        // Iterate over grid in reverse order
        for (int j = n - 2; j >= 0; j--) {
            for (int i = 0; i < m; i++) {
                // Check three possible moves
                if (i > 0 && grid[i][j] < grid[i - 1][j + 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + 1);
                }
                if (grid[i][j] < grid[i][j + 1]) {
                    dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1);
                }
                if (i < m - 1 && grid[i][j] < grid[i + 1][j + 1]) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 1);
                }
            }
        }

        // Find maximum value in the first column
        int maxMoves = 0;
        for (int i = 0; i < m; i++) {
            maxMoves = max(maxMoves, dp[i][0]);
        }

        return maxMoves;
    }
};

