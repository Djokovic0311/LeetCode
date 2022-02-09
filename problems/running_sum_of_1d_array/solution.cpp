class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            tmp += nums[i];
            nums[i] = tmp;
        }
        return nums;
    }
};