class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int ans=0,curr=0,last=nums[1]-nums[0];
        for(int i = 1; i < n-1; i++) {
            int cur_diff = nums[i+1] -nums[i];
            if(cur_diff == last) {
                curr++;
            }
            else {
                last = cur_diff;
                curr = 0;
            }
            ans += curr;
        }
        return ans;
    }
};
