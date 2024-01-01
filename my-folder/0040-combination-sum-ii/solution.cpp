class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& candidates, int target, vector<int>& cur, int sum, int idx) {
        int n = candidates.size();
        if(sum == target) {
            res.push_back(cur);
            return;
        }

        for(int i = idx; i < n; i++) {
            if(i != idx && candidates[i] == candidates[i-1]) {
                continue;
            }
            if(sum + candidates[i] <= target) {
                sum+= candidates[i];
                cur.push_back(candidates[i]);
                dfs(candidates, target, cur, sum, i+1);
                cur.pop_back();
                sum -= candidates[i];                
            } else return;

        }

        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        dfs(candidates, target, cur, 0,0);
        return res;
    }
};
