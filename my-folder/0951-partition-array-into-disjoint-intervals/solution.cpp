class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        int mx = nums[0], cur = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] < mx) {
                mx = cur;
                ans = i+1;
            }
            else if(nums[i] > cur) {
                cur = nums[i];
            }
        }
        return ans;
    }
};
