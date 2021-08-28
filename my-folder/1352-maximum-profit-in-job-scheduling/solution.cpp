class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        const int N = startTime.size();
        vector<vector<int>> jobs(N, vector<int>(3));
        for (int i = 0; i < N; ++i) {
            jobs[i][0] = endTime[i];
            jobs[i][1] = startTime[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp = {{0, 0}};
        for (const auto &job : jobs) {
            const auto cur = prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second) dp[job[0]] = cur;
        } 
        return dp.rbegin()->second;
    }
};
