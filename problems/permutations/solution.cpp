class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtracking(ans, curr, nums);
        return ans;
    }
    void backtracking(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums){
        if(nums.size() == curr.size()) {
            ans.push_back(curr);
            return;
        }

        for(int num : nums) {
            if(find(curr.begin(), curr.end(), num) == curr.end()) {
                curr.push_back(num);
                backtracking(ans, curr, nums);
                curr.pop_back();
            }
        }
    }
};