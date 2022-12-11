class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int res = -1;
        
        int n = nums.size();
        int len = nums[n-1];

        vector<int> dp(100001,0);
        
        for(int num : nums) {
            dp[num] = 1;
        }
        
        for(int i = 0; i < n; i++) {
            if(nums[i] <= 316){
                if(dp[nums[i] * nums[i]] == 1) {
                    dp[nums[i] * nums[i]] = dp[nums[i]]+1;
                }  
                
            }
            res = max(res, dp[nums[i]]);
        }
        // for(int p : dp) {
        //     cout << p << ' ';
        // }
        // cout << endl;
        return res < 2 ? -1 : res;
    }
};
