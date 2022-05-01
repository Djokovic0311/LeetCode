class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int res = INT_MAX;
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[cards[i]].push_back(i);
        }
        for(auto it = mp.begin(); it != mp.end(); it++) {
            vector<int> v = it->second;
            for(int i = 0; i < v.size()-1; i++)  {
                res = min(res, v[i+1]-v[i]+1);
            }
        }
        return res==INT_MAX?-1:res;
    }
};