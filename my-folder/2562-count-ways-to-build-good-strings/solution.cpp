class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,0);
        dp[0] =1;
        int res = 0;
        int mod = 1e9 + 7;
        
        for(int i = 0; i <= high; i++) {
            if(i >= zero)
                dp[i] = (dp[i] + dp[i-zero]) % mod;
            if(i >= one)
                dp[i] = (dp[i] + dp[i-one]) % mod;
            // cout << dp[i] << ' ';
            if(i>= low && i <= high)
                res = (res + dp[i]) % mod;
        }
        cout << endl;
        return res;
    }
};
