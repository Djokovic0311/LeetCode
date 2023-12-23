class Solution {
public:
    vector<int> arr;
    unordered_map<int,vector<int>> mp;
    Solution(vector<int>& nums) {
        arr=nums;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        return mp[target][rand()%mp[target].size()];
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
