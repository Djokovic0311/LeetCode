class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> res;
        int n = queries.size();
        unordered_map<int,int> mp;
        for(int i = 1; i <= m; i++) mp[i] = i;

        for(int q : queries) {
            res.push_back(mp[q]-1);
            for(auto it : mp) {
                if(it.second < mp[q]) {
                    mp[it.first]++;
                }
            }
            mp[q] = 1;
        }

        return res;
    }
};
