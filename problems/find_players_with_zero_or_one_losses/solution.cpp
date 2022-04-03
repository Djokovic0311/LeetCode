class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;
        vector<vector<int>> res (2,vector<int>());
        for(auto match : matches) {
            int winner = match[0];
            int loser = match[1];
            mp[loser]++;
            mp[winner] += 0;
        }
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(it->second == 0) res[0].push_back(it->first);
            if(it->second == 1) res[1].push_back(it->first);
        }
        sort(res[0].begin(),res[0].end());
        sort(res[1].begin(),res[1].end());
        return res;
    }
};