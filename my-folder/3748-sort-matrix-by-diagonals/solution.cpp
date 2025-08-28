class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mp[i-j].push_back(grid[i][j]);
            }
        }

        for(auto& entry : mp) {
            sort(entry.second.begin(), entry.second.end());
            if(entry.first >= 0) {
                reverse(entry.second.begin(), entry.second.end());
            } 
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                grid[i][j] = mp[i-j].front();
                mp[i-j].erase(mp[i-j].begin());
            }
        }

        return grid;
    }
};
