class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxVal = nums[n-1]+k+2;
        vector<int> count(maxVal, 0);
        for(int v : nums) count[v]++;
        for(int i = 1; i < maxVal; i++) {
            count[i] += count[i-1];
        }
        int res = 0;
        for(int i = 0; i < maxVal; i++) {
            int l = max(0, i - k);
            int r = min(i+k, maxVal-1);
            int total = count[r] - (l ? count[l-1] : 0);
            int freq = count[i] - (i ? count[i-1] : 0);
            res = max(res, freq + min(numOperations, total - freq));
        }
        return res;
    }
};
