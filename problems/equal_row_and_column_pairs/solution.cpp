class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        map<vector<int>,pair<int,int>> mp;
        for(int i = 0; i < n; i++) {
            mp[grid[i]].first++;
        }
        for(int j = 0; j < n; j++) {
            vector<int> tmp;
            for(int i = 0; i < n; i++)
                tmp.push_back(grid[i][j]);
            mp[tmp].second++;
        }
        for(auto it = mp.begin(); it != mp.end(); it++) {
            // cout << it->second.first << ' ' << it->second.second<< endl;
            res += (it->second.first) * (it->second.second);
            
        }
        return res;
    }
};