class Solution {
public:
    void backtracking(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, int start) {
        res.push_back(cur);

        for(int i = start; i < nums.size(); i++) {
            if(i > start && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            backtracking(res, cur, nums, i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(),nums.end()); 
        backtracking(res, cur, nums, 0);
        return res;
    }
};
