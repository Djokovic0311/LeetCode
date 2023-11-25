class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2));
        dp[0][0]=INT_MAX;  // free
        dp[0][1]=prices[0];  // pay
        
        for(int i=1;i<n;i++){
            int mini=INT_MAX;
            for(int j=i-1;j>=0;j--){
                if(i>=j+1 && i+1<=2*(j+1)){
                    mini=min(mini,dp[j][1]);
                }
            }
            dp[i][1]= prices[i]+min(dp[i-1][0],dp[i-1][1]);
            dp[i][0]=mini;
        }
        
        
        
        return min(dp[n-1][0],dp[n-1][1]);
    }
};
