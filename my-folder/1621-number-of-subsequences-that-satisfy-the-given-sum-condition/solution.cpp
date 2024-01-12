class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n-1;
        vector<int>pow2(n, 1);
        
        for(int i = 1; i < n; i++) {
            pow2[i] = 2 * pow2[i-1]% MOD;
        }
        int res = 0;
        while(l <= r) {
            if(nums[l] + nums[r] <= target) {
                res = (res+pow2[r-l++]) % MOD;
            }
            else{
                r--;
            }
        }
        return res;
    }
};
