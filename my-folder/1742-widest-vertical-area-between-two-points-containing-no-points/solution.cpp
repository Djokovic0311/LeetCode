class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int start = 0, end = 0;
        int res = 0;
        while(start < n && end  < n) {
            while(end < n && points[start][0] == points[end][0]){
                end++;

            }

            if(end < n)
                res = max(res, points[end][0]-points[start][0]);
            else res = max(res, points[n-1][0]-points[start][0]);
            start = end;
            
        }

        return res;
    }
};
