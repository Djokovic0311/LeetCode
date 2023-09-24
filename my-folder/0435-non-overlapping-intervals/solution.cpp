class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b) {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = -1;
        sort(intervals.begin(),intervals.end(),cmp);
        vector<int> prev = intervals[0];
        for(vector<int> i : intervals) {
            if(i[0] < prev[1]) {
                res++;
            }
            else prev = i;
        }
        return res;
    }
};
