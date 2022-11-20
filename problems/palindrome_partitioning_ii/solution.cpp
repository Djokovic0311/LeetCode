class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        bool pal[n][n];
        long dp[n];
        memset(pal, 0, sizeof(bool)*n*n);

        for(int i = n-1; i >= 0; i--) {
            dp[i] = INT_MAX;
            for(int j = i; j < n; j++) {
                if(s[i] == s[j] && (j-i < 2 || pal[i+1][j-1])) {
                    pal[i][j] = 1;
                    if(j == n-1)dp[i] = 0;
                    else dp[i] = min(dp[i], dp[j+1]+1);
                }
            }
        }
        return dp[0];
    }
};