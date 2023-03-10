class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string>word_Set(wordDict.begin(),wordDict.end());
        int n = s.length();
        vector<vector<string>> dp(n+1, vector<string>());
        dp[0].push_back("");

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j <= n; j++) {
                string tmp = s.substr(i, j-i);
                if(word_Set.count(tmp)) {
                    for(auto str : dp[i]) {
                        dp[j].push_back(str + (str == "" ? "" : " ") + tmp);
                    }
                }
            }
        }
        return dp[n];
    }
};
