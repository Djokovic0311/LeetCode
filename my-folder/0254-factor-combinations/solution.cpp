class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& cur, int n) {
        int i=cur.empty()?2:cur.back();
        for(;i<=n/i;i++){
            if(n%i==0){
                cur.push_back(i);
                cur.push_back(n/i);
                res.push_back(cur);
                cur.pop_back();
                dfs(cur,n/i);
                cur.pop_back();
            }
        } 
    }
    vector<vector<int>> getFactors(int n) {
        vector<int> v;
        dfs(v,n);
        return res;
        
    }
};
