class Solution {
public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        vector<int> dp(maxLength+1,0);
        dp[0] = 1;

        int mod = 1e9 + 7;
        for(int i = 1; i <= maxLength; i++) {
            int tmp = 0;
            if(i >= oneGroup) tmp += dp[i - oneGroup];
            tmp %= mod;
            if(i >= zeroGroup) tmp += dp[i-zeroGroup];
            tmp %= mod;
            dp[i] = tmp;
        }

        int ret = 0;
        for(int i = minLength; i <= maxLength; i++ ){   //refer to comment on line#6
            ret += dp[i];
            ret %= mod;
        }

        return ret;        
    }
};
