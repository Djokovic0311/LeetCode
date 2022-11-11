class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int i) {
        if(i == nums.size()) {
            res.push_back(nums);
            return;
        }
            
        for(int j = i;  j < nums.size(); j++) {
            swap(nums[i],nums[j]);
            dfs(nums, i+1);
            swap(nums[i],nums[j]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0);
        return res;
    }
};
