class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int minPrefixSum = 0, maxPrefixSum = 0;
        int prefixSum = 0;
        for(int i = 0; i < n; i++) {
            prefixSum += nums[i];
            maxPrefixSum = max(prefixSum, maxPrefixSum);
            minPrefixSum = min(prefixSum, minPrefixSum);
        }

        return abs(maxPrefixSum-minPrefixSum);
    }
};
