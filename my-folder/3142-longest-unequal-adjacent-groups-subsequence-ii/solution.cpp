class Solution {
public:
    int hammingDistance(const string& s1, const string& s2) {
        int distance = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                distance++;
            }
        }
        return distance;
    }

    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        // Step 1: Compute pair validity
        vector<vector<bool>> validPairs(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (i != j && 
                    words[i].size() == words[j].size() && 
                    groups[i] != groups[j] &&
                    hammingDistance(words[i], words[j]) == 1) 
                {
                    validPairs[i][j] = true;
                }
            }
        }

        // Step 2: Dynamic Programming
        vector<int> dp(n, 1), prev(n, -1);  // dp[i] = length of longest subsequence ending at i, prev[i] = previous index
        int maxLenIdx = 0;  // Index of the maximum length subsequence
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (validPairs[j][i] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxLenIdx]) {
                maxLenIdx = i;
            }
        }

        // Step 3: Backtrack to retrieve the words
        vector<string> result;
        for (int i = maxLenIdx; i >= 0; i = prev[i]) {
            result.push_back(words[i]);
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};

