class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        int n = coins.size();
        dp[0] = 1;
        for(auto c : coins) {
            for(int i = c; i <= amount; i++) {
                dp[i] += dp[i-c];
            }
         }
        return dp[amount];
    }
};
