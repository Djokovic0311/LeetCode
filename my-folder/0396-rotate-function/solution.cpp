class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int allSum = 0;
        int len = nums.size();
        int F = 0;
        for (int i = 0; i < len; i++) {
            F += i * nums[i];
            allSum += nums[i];
        }
        int mx = F;
        for (int i = len - 1; i >= 1; i--) {
            F = F + allSum - len * nums[i];
            mx = max(F, mx);
        }
        return mx;
    }
};
