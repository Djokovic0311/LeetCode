class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, INT_MIN));
        dp[0][nums[0] % 2] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            int parity = nums[i] % 2;
            dp[i][parity] = max(dp[i-1][parity] + nums[i], dp[i-1][1 - parity] + nums[i] - x);
            dp[i][1 - parity] = max(dp[i][1 - parity], dp[i-1][1 - parity]);
        }
        
        return max(dp[n-1][0], dp[n-1][1]);   
    }
};
