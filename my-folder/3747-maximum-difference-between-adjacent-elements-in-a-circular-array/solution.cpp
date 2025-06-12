class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            res = max(res,abs(nums[i]-nums[(i+1)%n]));
        }
        return res;
    }
};
