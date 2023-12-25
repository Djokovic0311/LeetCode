class Solution {
public:
    int minDistance(vector<int> points, int origin) {
        int distance = 0;
        for(int p : points) {
            distance += abs(origin-p);
        }
        return distance;
    }
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j= 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        sort(cols.begin(), cols.end());

        return minDistance(rows, rows[rows.size()/2]) + minDistance(cols, cols[cols.size()/2]);

    }
};
