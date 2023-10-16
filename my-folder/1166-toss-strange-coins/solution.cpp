class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<vector<double>> dp(n + 1, vector<double>(target + 1, 0.0));

        dp[0][0] = 1.0;  // Base case: 100% probability of 0 heads before any toss

        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][0] * (1 - prob[i - 1]); // Probability of 0 heads after i tosses
            for (int j = 1; j <= target && j <= i; ++j) {
                // Update the probability for j heads after i tosses
                dp[i][j] = dp[i - 1][j] * (1 - prob[i - 1]) + dp[i - 1][j - 1] * prob[i - 1];
            }
        }

        return dp[n][target];        
    }
};
