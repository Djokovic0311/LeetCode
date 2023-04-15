class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> widths(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int length = grid[i][j] >= 0 ? to_string(grid[i][j]).length() : to_string(-grid[i][j]).length() + 1;
                widths[j] = max(widths[j], length);
            }
        }
        return widths;
    }
};
