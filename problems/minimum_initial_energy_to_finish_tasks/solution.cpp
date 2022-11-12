class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int res = 0;
        for (auto &a : tasks)
            a[0] = a[1] - a[0];
        sort(tasks.begin(), tasks.end());
        for (auto &a : tasks)
            res = max(res + a[1] - a[0], a[1]);
        return res;        
    }
};