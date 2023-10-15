class Solution {
public:
    int numWays(int steps, int arrLen) {
    const int MOD = 1e9 + 7;
        int maxColumn = std::min(arrLen, steps / 2 + 1); // Boundary condition
    std::vector<std::vector<int>> dp(steps + 1, std::vector<int>(maxColumn, 0));
    dp[0][0] = 1; // Base case: 0 steps and at index 0
    
    for (int i = 1; i <= steps; ++i) {
        for (int j = 0; j < maxColumn; ++j) {
            // Stay in the same place
            dp[i][j] = dp[i-1][j];
            
            // Move to the right if possible
            if (j - 1 >= 0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
            }
            
            // Move to the left if possible
            if (j + 1 < maxColumn) {
                dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
            }
        }
    }
    
    return dp[steps][0];    
    }
};
