class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        vector<int> r(n,0), c(n,0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                r[i] = max(r[i],grid[i][j]);
                c[j] = max(c[j], grid[i][j]);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                res += min(r[i],c[j])-grid[i][j];
                // res += (c[j]-grid[i][j]);
            }
        }
        return res;
    }
};