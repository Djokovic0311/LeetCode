class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n, vector<int>(n));
        
        for(int gap = 0; gap < n; gap++)
            for(int i = 0, j = gap; j < n; i++, j++){
                if(gap == 0) dp[i][j] = piles[i];
                else if(gap == 1) dp[i][j] = max(piles[i], piles[j]);
                else{
                    int case1 = piles[i] + min(dp[i+2][j], dp[i+1][j-1]);
                    int case2 = piles[j] + min(dp[i+1][j-1], dp[i][j-2]);
                    dp[i][j] = max(case1, case2); // maximum of these 2 cases
                }
            }
        return dp[0][n-1];
    }
};
