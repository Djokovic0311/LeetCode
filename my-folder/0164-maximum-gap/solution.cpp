class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-1; i++) {
            res = max(res, nums[i+1]-nums[i]);
        }
        return res;
    }
};
