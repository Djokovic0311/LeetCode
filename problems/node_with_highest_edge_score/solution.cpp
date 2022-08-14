class Solution {
public:
    int edgeScore(vector<int>& edges) {
        
        int n = edges.size();
        vector<long long> mp(n,0);
        for(int i = 0; i < n; i++) {
            mp[edges[i]] += i;
        }
        long long res = 0;
        int index = -1;
        for(int i = 0; i < n; i++) {
            if(res < mp[i]) {
                res = mp[i];
                index = i;
            }
        }
        return index;
    }
};