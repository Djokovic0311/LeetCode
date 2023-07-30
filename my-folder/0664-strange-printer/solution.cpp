class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = len; // At most, print one character at a time
                for (int k = i; k < j; k++) {
                    int temp = dp[i][k] + dp[k+1][j];
                    // when s[k] == s[j], we could do the operation in one turn 
                    if (s[k] == s[j]) {
                        temp--;
                    }
                    dp[i][j] = min(dp[i][j], temp);
                }
            }
        }
        return dp[0][n-1];        
    }
};
