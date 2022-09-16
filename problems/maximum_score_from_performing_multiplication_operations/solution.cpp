class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        int res = 0;
        vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
        for(int i = 0; i < m; i++) {
            dp[i][m] = 0;
            dp.back()[i] = 0;
        }
        for(int i = m-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                 dp[i][j] = max(multipliers[i]*nums[j] + dp[i+1][j+1],
                                    multipliers[i]*nums[n-1-(abs(i-j))] + dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};