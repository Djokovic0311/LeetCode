class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = nums[0];
        int maxSum = dp;
        for(int i = 1; i < nums.size(); i++){
            dp = max(dp + nums[i], nums[i]);
            maxSum = max(maxSum, dp);
        }
        return maxSum;        
    }
};