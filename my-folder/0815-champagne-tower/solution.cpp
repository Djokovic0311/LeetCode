class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[100] = {};
        dp[0] = poured;
        for (int i = 1; i <= query_row; i++)
        {
            for (int j = i-1; j >= 0; j--)
            {
				double remain = (max(dp[j], 1.0) - 1.0) / 2.0;
				
                dp[j+1] += remain;
                dp[j] = remain;
            }
        }
        return dp[query_glass] >= 1 ? 1: dp[query_glass];        
    }
};
