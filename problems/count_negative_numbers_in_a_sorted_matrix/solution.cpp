class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] >= 0) ;
                else {
                    res += (n - j);
                    // cout << res <<endl;
                    break;
                }
            }
        }
        return res;
    }
};