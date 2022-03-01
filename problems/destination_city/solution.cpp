class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int m = paths.size();
        
        unordered_map<string, int> mp;
        for(int i = 0; i < m; i++)
           mp[paths[i][0]]++;
        
        for(int i = 0; i < m; i++)
        {
            if(mp[paths[i][1]] < 1)
                return paths[i][1];
        }
        
        return "";      
    }
};