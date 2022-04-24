class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int n = circles.size();
        set<pair<int,int>> st;
        for(int i = 0; i < n; i++) {
            long long x = circles[i][0], y = circles[i][1], r = circles[i][2];
            for(long long j = x-r; j <=x+r; j++) {
                for(long long k = y-r; k <= y+r; k++) {
                    if((j-x)* (j-x) + (k-y) * (k-y) <= r * r)
                        st.insert({int(j),int(k)});
                }
            }
        }
        return st.size();
    }
};
