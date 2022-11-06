class Solution {
public:
    const long long INF = 1e18 + 7;
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<vector<long long>> dp(m + 1, vector<long long> (n + 1, INF));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
                long long add = 0;
                for (int l = 1; l <= factory[i][1]; l++) {
                    if (j + l <= n) {
                        add += abs(factory[i][0] - robot[j + l - 1]);
                        dp[i + 1][j + l] = min(dp[i + 1][j + l], dp[i][j] + add);
                    }
                }
            }
        }
        long long sol = INF;
        for (int i = 0; i <= m; i++) {
            sol = min(sol, dp[i][n]);
        }
        return sol;
    }
};
