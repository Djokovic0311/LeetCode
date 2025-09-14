class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        int res = INT_MAX;
        for(auto t : tasks) {
            res = min(res, t[0]+t[1]);
        }
        return res;
    }
};
