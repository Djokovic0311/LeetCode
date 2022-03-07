class Solution {
public:
    int countPoints(string rings) {
        int n = rings.size();
        vector<set<char>> v(100);
        int res = 0;
        for(int i = 0; i < n-1; i += 2) {
            v[rings[i+1]-'0'].insert(rings[i]);
        }
        for(int i = 0; i < 100; i++) {
            if(v[i].size() == 3) res++;
        }
        return res;
    }
};