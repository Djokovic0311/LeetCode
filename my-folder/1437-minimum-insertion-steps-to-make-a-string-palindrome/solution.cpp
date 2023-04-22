class Solution {
public:
    int minInsertions(string s) {
    int n = s.length();
    
    // Create a 2D vector to store the minimum number of steps for substrings
    vector<std::vector<int>> dp(n, vector<int>(n, 0));
    
    // Iterate through the substrings in reverse order
    for (int l = 1; l < n; ++l) {
        int i = 0;
        int j = l;
        while (j < n) {
            // If the characters at the current indices are the same,
            // we don't need to insert any character, so the value remains the same as for the previous substring
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                // If the characters are different, we need to insert a character, so we take the minimum
                // of the two possible insertions and add 1
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
            
            i++;
            j++;
        }
    }
    
    return dp[0][n - 1];        
    }
};
