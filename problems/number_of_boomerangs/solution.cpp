class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, int> mp;
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int d = pow(points[j][1] - points[i][1], 2) + pow(points[j][0] - points[i][0], 2);
                res += 2 * mp[d]++;
            }
            mp.clear();
        }
        return res;
            
    }
};