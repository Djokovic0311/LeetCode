class Solution {
public:
    int numSquares(int n) {
        if(n==1||n==2||n==3)return n;
        vector<int> dp(n+1,1e9);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i=4;i<=n;i++){
            for(int j=1;j<=sqrt(n);j++){
                if(i>=j*j){
                    dp[i] = min(dp[i],1+dp[i-j*j]);
                }
            }
        }
        return dp[n];
    }
};
