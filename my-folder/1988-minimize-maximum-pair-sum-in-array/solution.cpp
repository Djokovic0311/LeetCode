class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = INT_MIN;
        for(int i = 0; i < n; i++) {
            res = max(res, nums[i] + nums[n-1-i]);
        }
        return res;
    }
};
