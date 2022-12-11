class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            sort(grid[i].begin(), grid[i].end());
        }
        for(int i = 0; i < n; i++) {
            priority_queue<int> pq;
            for(int j = 0; j < m; j++) {
                pq.push(grid[j][i]);
            }
            res += pq.top();
        }
        return res;
    }
};
