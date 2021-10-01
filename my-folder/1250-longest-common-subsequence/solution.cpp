class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<short>> pic(m + 1, vector<short>(n+ 1));
          for (auto i = 1; i <= m; ++i)
            for (auto j = 1; j <= n; ++j)
              if (text1[i - 1] == text2[j - 1]) pic[i][j] = pic[i - 1][j - 1] + 1;
              else pic[i][j] = max(pic[i - 1][j], pic[i][j - 1]);
          return pic[m][n];
    }
};
