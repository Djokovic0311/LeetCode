class Solution {
public:
    bool validPartition(vector<int>& nums) {
        bool dp[4] = {true, false, nums[0] == nums[1], false};
        for (int i = 2; i < nums.size(); ++i) {
            bool two = nums[i] == nums[i - 1];
            bool three = (two && nums[i] == nums[i - 2]) || (nums[i] - 1 ==  nums[i - 1] && nums[i] - 2 == nums[i - 2]);
            dp[(i + 1) % 4] = (dp[(i - 1) % 4] && two) || (dp[(i - 2) % 4] && three);
        }
        return dp[nums.size() % 4];        
    }
};
