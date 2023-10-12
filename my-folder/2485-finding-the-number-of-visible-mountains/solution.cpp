class Solution {
public:
    int visibleMountains(vector<vector<int>>& peaks) {
        sort(peaks.begin(), peaks.end(), [](const vector<int>& a, const vector<int>& b){
            int ya = a[1]-a[0], yb = b[1]-b[0];
            if (ya != yb) return ya > yb;
            
            int xa = a[0]+a[1], xb = b[0]+b[1];
            return xa > xb;
        });
        
        int maxx = 0;
        int res = 0;
        int n = peaks.size();
        for (int i = 0; i < n; i++) {
            int x = peaks[i][0]+peaks[i][1];
            if (x > maxx) {
                if (i+1 == n || peaks[i][0] != peaks[i+1][0] || peaks[i][1] != peaks[i+1][1])
                    res++;
                maxx = x;
            }
        }
        return res;
    }
};
