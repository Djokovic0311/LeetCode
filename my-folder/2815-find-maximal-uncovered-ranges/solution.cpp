class Solution {
public:
    vector<vector<int>> findMaximalUncoveredRanges(int n, vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int l = ranges.size();
        vector<vector<int>> res;
        int left = 0;
        for(int i = 0; i < l; ) {
            int start = ranges[i][0], end = ranges[i][1] + 1;
            int j = i+1;
            while(j < l && ranges[j][0] <= end) {
                end = max(end, ranges[j][1]+1);
                j++;
            }
            if(start > 0) { 
                res.push_back(vector<int> {left, start-1});
            }

            i = j;
            left = end;
        }

        if(left <= n-1) {
            res.push_back({left, n-1});
            
        }

        return res;
    }
};
