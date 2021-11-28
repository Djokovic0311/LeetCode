class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long sum = 0;
        int n= nums.size();
        vector<int> res(n, -1);
        if(n <= 2 * k) return res;
        if(k == 0) return nums;
        for(int i = 0; i < 2 * k + 1; i++) sum += nums[i];
        
        res[k] = sum / (2 * k + 1);
        for(int i = k+1; i < n-k; i++) {
            sum = sum - nums[i-k-1] + nums[i+k];
            res[i] = sum / (2 * k + 1);
        }
        return res;
    }
};