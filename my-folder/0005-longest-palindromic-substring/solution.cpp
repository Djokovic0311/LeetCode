class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,1));
        int maxlen = 1;
        int head = 0;
        for (int len = 2; len <= n; ++len)
            for (int i = 0, j; (j=i+len-1) < n; ++i) 
            {
                dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1];
                if (dp[i][j] && len > maxlen) head = i, maxlen = len;
            }
        return s.substr(head, maxlen);
    }
};
