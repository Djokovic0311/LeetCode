class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int mod = 1e9 + 7;
        int n = types.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int counti = types[i-1][0];
            int marksi = types[i-1][1];
            for (int j = 0; j <= target; j++) {
                for (int k = 0; k <= counti; k++) {
                    if (j - k * marksi >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i-1][j - k * marksi]) % mod;
                    }
                }
            }
        }
        return dp[n][target];        
    }
};