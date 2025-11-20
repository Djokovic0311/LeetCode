class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto& a, auto& b) {
            if(a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int res = 0;
        int n = intervals.size();
        vector<int> containing(n, 2);
        while(--n >= 0) {
            int s = intervals[n][0], e = intervals[n][1];
            int num = containing[n];
            for(int i = s; i < s+num; i++) {
                for(int j = 0; j <= n; j++) {
                    if(containing[j] > 0 && i <= intervals[j][1]) {
                        containing[j]--;
                    }
                }
                res++;
            }
        }
        return res;
    }
};
