class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n = nums.size();
        int c = abs(nums[0]);
        int res = nums[0];
        for(int i = 1; i < n; i++) {
            if(abs(nums[i]) < c) {
                c = abs(nums[i]);
                res = nums[i];
            }
            else if(abs(nums[i]) == c) {
                if(res < nums[i]) {
                    res = nums[i];
                }
            }
        }
        return res;
    }
};
