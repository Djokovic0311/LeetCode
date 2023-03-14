class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 1;
        sort(nums.begin(), nums.end());

        int l = 0, r = 0;
        while(l < n && r < n) {
            while(r < n && nums[r] - nums[l] <= k) {
                r++;
            }
            if(r < n && nums[r] - nums[l] > k) {
                res++;
            }
            if(r == n) break;
            l = r;
        }

        return res;
    }
};
