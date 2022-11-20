class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& tmp, int n, int bottom) {
        for(int i = bottom; i * i <= n; i++) {
            if(n % i == 0) {
                vector<int> new_line = tmp;
                new_line.push_back(i);
                dfs(res, new_line, n/i, i);
                new_line.push_back(n/i);
                for(int p : new_line)
                    cout << p << ' ';
                cout << endl;
                res.push_back(new_line);
            }
        }
    }
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, tmp, n, 2);
        return res;
    }
};