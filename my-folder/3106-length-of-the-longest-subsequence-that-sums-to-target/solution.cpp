class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        dp[0][0] = 0;
        if (nums[0] <= target) dp[0][nums[0]] = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= target; ++j) {
                // Exclude nums[i]
                dp[i][j] = dp[i-1][j];

                // Include nums[i]
                if (j >= nums[i] && dp[i-1][j-nums[i]] != -1) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-nums[i]] + 1);
                }
            }
        }

        if (dp[n-1][target] == 0) return -1;  // if no valid subsequence found
        return dp[n-1][target];    
    }
};
