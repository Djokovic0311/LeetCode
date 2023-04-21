class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int MOD = 1e9 + 7;
        int numCrimes = group.size();
        vector<vector<vector<int>>> dp(numCrimes + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));

        dp[0][0][0] = 1;

        for (int i = 1; i <= numCrimes; i++) {
            int currentGroup = group[i - 1];
            int currentProfit = profit[i - 1];

            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= minProfit; k++) {
                    dp[i][j][k] = dp[i - 1][j][k]; // not selecting the current crime

                    if (j >= currentGroup) {
                        int newProfit = max(0, k - currentProfit);
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - currentGroup][newProfit]) % MOD;
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans = (ans + dp[numCrimes][i][minProfit]) % MOD;
        }

        return ans;
    }
};
