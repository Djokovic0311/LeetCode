class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        long res = 0, mod = 1e9+7;
        int n = nums.size();
        vector<int> count(n,0);
        for(auto r : requests) {
            count[r[0]]++;
            if(r[1]+1 <n)
                count[r[1]+1] --;
        }
        for (int i = 1; i < n; ++i)
            count[i] += count[i - 1];

        sort(nums.begin(), nums.end());
        sort(count.begin(), count.end());
        for(int i = 0; i < n; i++) {
            res += (long) nums[i] * count[i];
        }

        return res % mod;
    }
};
