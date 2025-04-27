class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for(int i = 0; i < n-2; i++) {
            if(2*(nums[i] + nums[i+2]) == nums[i+1]) {
                result++;
            }
        }
        return result;
    }
};
