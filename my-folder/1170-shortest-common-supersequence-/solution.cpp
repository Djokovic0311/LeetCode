class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        
        // Step 1: Compute LCS using dynamic programming
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Step 2: Reconstruct the SCS from the LCS table
        string result;
        int i = m, j = n;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result.push_back(str1[i - 1]);
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                result.push_back(str1[i - 1]);
                i--;
            } else {
                result.push_back(str2[j - 1]);
                j--;
            }
        }

        // Append remaining characters
        while (i > 0) {
            result.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            result.push_back(str2[j - 1]);
            j--;
        }

        // Reverse the string to get the correct order
        reverse(result.begin(), result.end());
        return result;       
    }
};
