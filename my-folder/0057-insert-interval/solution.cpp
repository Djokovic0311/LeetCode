class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int idx = 0;
        while(idx < n && intervals[idx][1] < newInterval[0]) {
            res.push_back(intervals[idx]);
            idx++;
        }

        while(idx < n && newInterval[1] >= intervals[idx][0]) {
            newInterval[0] = min(newInterval[0], intervals[idx][0]);
            newInterval[1] = max(newInterval[1], intervals[idx][1]);
            idx++;
        }
        res.push_back(newInterval);
        while(idx < n) {
            res.push_back(intervals[idx++]);
        }

        return res;        
    }
};
