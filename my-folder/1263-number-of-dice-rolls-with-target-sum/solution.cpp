class Solution {
public:
    
    int numRollsToTarget(int d, int f, int target) {
        int M = 1e9+7;
        int dp[d+1][target+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=d;i++){
            for(int j=1;j<=target;j++){
                for(int x=1;x<=f&&j-x>=0;x++){
                    dp[i][j] +=dp[i-1][j-x];
                    dp[i][j]= dp[i][j]%M;
                }
            }
        }
        return dp[d][target];
    }
};
