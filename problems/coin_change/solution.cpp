class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(++amount);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for(int i = 1; i < amount; i++) {
            dp[i] = INT_MAX;
            for(int j = 0; j < n; j++) {
                if(i-coins[j]<0) break;
                if(dp[i-coins[j]] != INT_MAX)
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                
            }
        }
        return dp[--amount] == INT_MAX ? -1: dp[amount];
    }
};