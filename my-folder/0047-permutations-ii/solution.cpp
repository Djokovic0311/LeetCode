class Solution {
public:
    void dfs(vector<int> nums, vector<vector<int>>& output, int idx) {
        if(idx == nums.size()) {
            output.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); i++) {
            if(i != idx && nums[i] == nums[idx]) continue;
            swap(nums[i], nums[idx]);
            dfs(nums, output, idx+1);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        dfs(nums, res, 0);
        return res;        
    }
};
