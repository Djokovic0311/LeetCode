class Solution {
public:
    vector<pair<int, int>> dirs = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};


    bool is_valid(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        set<int> visited;
        visited.insert(grid[0][0]);
        int cur_i = 0, cur_j = 0;
        for(int cnt = 1; cnt < n * n; cnt++) {
            bool found = false;
            // cout << cnt << endl;
            // cout << cur_i << " " << cur_j << endl;
            for(auto& [di, dj] : dirs) {
                int ni = cur_i + di, nj = cur_j + dj;
                // cout << ni << " " <<  nj << endl;
                // cout << is_valid(ni, nj, n) << endl;
                if(is_valid(ni, nj, n) && visited.find(grid[ni][nj]) == visited.end() && grid[ni][nj] == grid[cur_i][cur_j]+1) {
                    
                    cur_i = ni, cur_j = nj;
                    visited.insert(grid[ni][nj]);
                    found = true;
                    break;
                }
            }
            if(!found) return false;
        }
        return true;
    }
};
