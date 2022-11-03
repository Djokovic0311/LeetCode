class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(4, vector<int>(n + 2, 0));
        int ans = 0;
        for(int i = 1; i <= m; i++) {
            fill(dp[1].begin(), dp[1].end(), 0);
            int prev = dp[2][0];
            for(int j = 1; j <= n; j++) {
                int tmp = dp[2][j];
                if(mat[i - 1][j - 1] == 0) {
                    dp[0][j] = dp[1][j] = dp[2][j] = dp[3][j] = 0;
                }
                else {
                    dp[0][j] = dp[0][j] + 1;
                    dp[1][j] = dp[1][j - 1] + 1;
                    dp[2][j] = prev + 1;
                    dp[3][j] = dp[3][j + 1] + 1;
                    ans = max({ans, dp[0][j], dp[1][j], dp[2][j], dp[3][j]});
                }
                prev = tmp;
            }
        }
        return ans;
    }
};