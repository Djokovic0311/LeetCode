class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int count = 1;
        int n = nums.size();
        int precnt = 0;
        int res = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                count++;
            } else {
                precnt = count;
                count = 1;
            }
            res = max(res, min(precnt, count));
            res = max(res, count/2);
        }
        return res >= k;
    }
};
