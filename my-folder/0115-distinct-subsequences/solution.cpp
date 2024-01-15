class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        // dp[i][j] : the number of distinct subsequences of s[i,m-1] and t[j,n-1]
        vector<vector<unsigned long long>> dp(m+1, vector<unsigned long long> (n+1,0));
        // empty string s cannot match t
        for(int j = 0; j <= n; j++) {
            dp[m][j] = 0;
        }
        // empty string t will have one match
        for(int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j>= 0; j--) {
                dp[i][j] = dp[i+1][j];
                if(s[i] == t[j]) {
                    dp[i][j] += dp[i+1][j+1];
                }
            }
        }

        return dp[0][0];
    }
};
