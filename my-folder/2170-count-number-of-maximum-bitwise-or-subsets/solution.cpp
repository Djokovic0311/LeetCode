class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int res = 0;
        vector<int> dp(1<<17, 0);
        dp[0] = 1;
        for(int num : nums) {
            for(int i = res; i>= 0; i--) {
                dp[i | num] += dp[i];
            }
            res = max(res, res|num);
        }

        return dp[res];
    }
};
