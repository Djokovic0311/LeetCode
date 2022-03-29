class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> one;
        find(0,nums, one, res);
        return vector<vector<int>>(res.begin(),res.end());
    }
    void find(int p, vector<int>& nums, vector<int>& one, set<vector<int>>& res) {
        if(p==nums.size()) {
            if(one.size()>1) res.insert(one);
            return;
        }
        if(one.empty()||nums[p]>=one.back()) {
            one.push_back(nums[p]);
            find(p+1,nums,one,res);
            one.pop_back();
        }
        find(p+1,nums,one,res);
    }
};