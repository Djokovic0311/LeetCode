class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& candidates, int target, int idx, vector<int>& cur, int sum) {
        if(sum == target) {
            res.push_back(cur);
            return;
        }
        for(int i = idx; i < candidates.size(); i++) {
            if(i != idx && candidates[i] == candidates[i-1])
                continue;
            if(sum + candidates[i] <= target) {
                sum += candidates[i];
                cur.push_back(candidates[i]);
                dfs(candidates, target, i+1, cur, sum);
                cur.pop_back();
                sum -= candidates[i];
            }
            else return;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        vector<int> cur;
        dfs(candidates, target, 0, cur, 0);
        return res;
    }
};