class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9+7;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; pow(i, x) <= n; i++) {
            for(int j = n; j >= pow(i, x); j--) {
                dp[j] = (dp[j] + dp[j-(int)pow(i, x)]) % MOD;
            }
        }
        return dp[n];
    }
};
