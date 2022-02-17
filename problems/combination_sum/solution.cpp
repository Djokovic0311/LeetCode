class Solution {
public:
    void combination(vector<int>& candidates, vector<int>& r, int target, vector<vector<int>>& res, int i) {
        if(target == 0) {
            res.push_back(r);
            return;
        }
        while(i < candidates.size() && target-candidates[i] >= 0) {
            r.push_back(candidates[i]);
            combination(candidates,r,target-candidates[i],res,i);
            i++;
            r.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        vector<int> r;
        vector<vector<int>> res;
        combination(candidates,r,target,res,0);
        return res;
    }
};  