class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                if(i == n-1) return n-1;
                if(nums[i] > nums[i+1]) {
                    return i;
                }
            }
        }
        return -1;
    }
};
