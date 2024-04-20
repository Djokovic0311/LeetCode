class Solution {
public:
    void dfs(vector<vector<int>>& land, int x, int y, int& minX, int& minY, int& maxX, int& maxY) {
        int m = land.size();
        int n = land[0].size();
        
        // Boundary check and visit check
        if (x < 0 || y < 0 || x >= m || y >= n || land[x][y] != 1) return;
        
        // Mark this cell as visited by setting it to 0
        land[x][y] = 0;
        
        // Update the boundaries of the current group
        minX = min(minX, x);
        minY = min(minY, y);
        maxX = max(maxX, x);
        maxY = max(maxY, y);
        
        // Visit all 4 possible directions
        dfs(land, x + 1, y, minX, minY, maxX, maxY);
        dfs(land, x - 1, y, minX, minY, maxX, maxY);
        dfs(land, x, y + 1, minX, minY, maxX, maxY);
        dfs(land, x, y - 1, minX, minY, maxX, maxY);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> groups;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    int minX = i, minY = j, maxX = i, maxY = j;
                    dfs(land, i, j, minX, minY, maxX, maxY);
                    groups.push_back({minX, minY, maxX, maxY});
                }
            }
        }
        
        return groups;        
    }
};
