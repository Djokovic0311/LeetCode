class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int res = 0;
        vector<vector<int>> record(m, vector<int>(n,0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(j == 0) {
                    record[i][0] = mat[i][0];
                } else {
                    record[i][j] = (mat[i][j] == 0) ? 0 : record[i][j-1]+1;
                }
                int cur = record[i][j];
                for(int k = i; k >= 0; k--) {
                    cur = min(cur, record[k][j]);
                    if(cur == 0) break;
                    res += cur;
                }
            }
        }
        return res;
    }
};
