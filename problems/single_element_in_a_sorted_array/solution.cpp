class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        for(int i = 0; i < n - 2; i+=2) {
            if(nums[i+1] != nums[i]) return nums[i];
        }
        return nums[n-1];
    }
};