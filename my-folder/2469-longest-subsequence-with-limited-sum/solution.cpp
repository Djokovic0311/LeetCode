class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> res(m,0);
        sort(nums.begin(),nums.end());
        vector<int> presum(n,0);
        presum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            presum[i] = nums[i] + presum[i-1];
        }
        int l = 0, r = n-1;
        for(int j = 0; j < m; j++) {
            int idx = upper_bound(presum.begin(), presum.end(), queries[j])-presum.begin();
            res[j] = idx;
        }
        return res;
    }
};
