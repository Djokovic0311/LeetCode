class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> res(n);
        pair<int, int> pos[n];
        auto endOfPos = pos + n;
        for (int i = 0; i < n; i++) pos[i] = {intervals[i][0], i};
        sort(pos, endOfPos);
        for (int i = 0; i < n; i++) {
            auto p = lower_bound(pos, endOfPos, intervals[i][1], [](auto it, int val){return it.first < val;});
            res[i] = p == endOfPos ? -1 : p->second;
        }
        return res;        
    }
};