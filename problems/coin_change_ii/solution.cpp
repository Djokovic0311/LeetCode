class Solution {
public:
    // int helper(vector<int>& coins, int amount, int cur, ) {
    //     if(cur == amount)
    // }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        vector<int> dp(5001,0);
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