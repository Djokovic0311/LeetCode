class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        

        int n = nums.size();
        vector<int> pre(n);
        vector<int> suf(n);
        sort(nums.begin(), nums.end());
        
        pre[0] = nums[0];
        suf[n - 1] = nums[n - 1];
        
        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], nums[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            suf[i] = min(suf[i + 1], nums[i]);
        }

        int res = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            res = min(res, abs(pre[i] - suf[i + 1]));
        }

        return res;        
    }
};
