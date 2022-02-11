class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size();
        int mi = INT_MAX;
        int index = -1;
        for(int i = 0; i < n; i++) {
            if(x == points[i][0] || y == points[i][1]) {
                if(abs(points[i][0]-x) + abs(points[i][1]-y) < mi) {
                    index = i;
                    mi = abs(points[i][0]-x) + abs(points[i][1]-y);
                }
            } 
        }
        return index;
    }
};
