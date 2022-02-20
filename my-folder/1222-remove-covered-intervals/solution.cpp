class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
             [] (const vector<int>& v1, const vector<int>& v2) { 
                 if(v1[0] != v2[0]) return v1[0] < v2[0];
                 else return v1[1] > v2[1];
        });
        
        int ans = intervals.size(), end = INT_MIN;
        
        for(int i = 0; i < intervals.size(); i++) {
            if(intervals[i][1] <= end) --ans; 
            else end = intervals[i][1];
        }
        
        return ans;        
    }
};
