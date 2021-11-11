class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            res = min(res, sum);
        }
        return 1-res > 0? 1-res:1;
    }
};