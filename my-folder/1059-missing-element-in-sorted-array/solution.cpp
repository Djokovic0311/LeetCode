class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i < n-1; i++) {
            if((cnt + nums[i+1] - nums[i] - 1) < k) {
                // cout << cnt + nums[i+1] - nums[i] - 1 << endl;
                cnt += nums[i+1] - nums[i] - 1;
            }
            else {
                return k-cnt + nums[i];
            }
           
        }
        return k-cnt + nums[n-1];
    }
};
