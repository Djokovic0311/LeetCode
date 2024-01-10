class Solution {
public:
    void dfs(vector<vector<int>> &grid, int r, int c, string &s) {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
            return;
        }
        grid[r][c] = 0;
        vector<vector<int>> dir{{0,1},{0,-1}, {1,0}, {-1,0}};
        vector<string> path{"r", "l", "d", "u"};
        for(int i = 0; i < 4; i++) {
            s += path[i];
            dfs(grid, r + dir[i][0], c + dir[i][1], s);
        }
        s += "e"; // end
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        int count = 0;
        unordered_set<string> uset;
        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[0].size(); ++c) {
                if(grid[r][c] == 1) {
                    string s = "s"; // start
                    dfs(grid, r, c, s);
                    uset.insert(s);
                }
            }
        }
        return uset.size();
    }
};
