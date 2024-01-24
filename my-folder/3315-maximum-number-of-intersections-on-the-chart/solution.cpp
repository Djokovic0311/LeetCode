class Solution {
public:
    int maxIntersectionCount(vector<int>& y) {
        int n = y.size();
        map<int,int> intervals;
        for(int i = 1; i < n; i++) {
            auto s = 2 * y[i-1], e = 2 * y[i] + (i == n-1 ? 0 : y[i] > y[i-1] ? -1 : 1);
            // cout << s << " " << e << endl;
            // build sweep line
            intervals[min(s,e)]++;
            intervals[max(s,e)+1]--;            
        }

        int res = 0, count = 0;
        for(const auto&[y, c] : intervals) {
            // cout << y << " " << c << endl;
            res = max(res, count += c);
        }

        return res;
    }
};
