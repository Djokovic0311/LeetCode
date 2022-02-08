class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                for(int j = 1; i+j < n && j <=k; j++) {
                    if(nums[i+j] == 1) return false;
                }
            }
        }
        return true;
    }
};