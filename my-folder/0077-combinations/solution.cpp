class Solution {
public:
    vector<vector<int>> ans;
    void helper(int n, int k, int idx, vector<int>& curr) {
        if(curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        for(int i = idx; i < n+1; i++) {
            curr.push_back(i);
            helper(n,k,i+1,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        helper(n,k,1,curr);
        return ans;
    }
};
