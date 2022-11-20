class Solution {
public:
    void helper(vector<int>& candidates, vector<int>& r, int target, int i, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(r);
            return;
        }
        while(i < candidates.size() && target - candidates[i] >= 0) {
            r.push_back(candidates[i]);
            helper(candidates, r, target-candidates[i],i, res);
            i++;
            r.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());

        vector<vector<int>> res;
        vector<int> r;
        helper(candidates,r, target,0,res);
        return res;
    }
};
