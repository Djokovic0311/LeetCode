class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        int cur = nums[0];
        for(int i = 1; i < n; i++){
            cur = max(nums[i], nums[i] + cur);
            mx = max(mx, cur);
        }
        return mx;
    }
};
