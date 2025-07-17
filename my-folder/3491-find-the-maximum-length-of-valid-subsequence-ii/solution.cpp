class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int res = 0;
        for(int num: nums) {
            num %= k;
            for(int i = 0; i < k; i++) {
                dp[i][num] = dp[num][i] + 1;
                res = max(res, dp[i][num]);
            }
        }
        return res;
    }
};
