class Solution {
public:
    vector<vector<int>> dp;     
    int helper(string& s, int i, int j) {
        if (dp[i][j])   return dp[i][j];
        if(i > j)       return 0;
        if(i == j)      return 1;
        if (s[i] == s[j]) 
            dp[i][j] = 2 + helper(s, i + 1, j - 1);
        else 
            dp[i][j] = max(helper(s, i + 1, j), helper(s, i, j - 1));
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int l = s.length();
        dp.resize(l, vector<int> (l,0));
        return helper(s,0,l-1);
    }
};
