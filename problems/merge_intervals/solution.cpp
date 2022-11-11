class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        if(intervals.size()<=1) return intervals;
        res.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= res.back()[1])
            {
                int s = res.back()[0], e = max(res.back()[1], intervals[i][1]);
                res.pop_back();
                res.push_back({s,e});
            }
            else res.push_back(intervals[i]);
        }
        return res;
    }
};