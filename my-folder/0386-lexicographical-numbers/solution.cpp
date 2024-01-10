class Solution {
public:
    void dfs(int sum, int n, vector<int>& res) {
        if(sum > n) {
            return;
        }

        for(int i = 0; i <= 9; i ++) {
            if(sum*10 + i <= n) {
                res.push_back(sum*10+i);
                dfs(sum * 10 + i, n, res);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i = 1; i <= 9; i++) {
            if(i <= n) {
                res.push_back(i);
                dfs(i, n, res);
            }
        }
        return res;
    }
};
