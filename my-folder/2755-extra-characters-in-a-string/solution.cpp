class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<std::string> dict(dictionary.begin(), dictionary.end());
        int n = s.length();
        vector<int> dp(n+1, n);
        dp[0] = 0;
        
        for(int i=1; i<=n; i++) {
            for(int j=0; j<i; j++) {
                if(dict.count(s.substr(j, i-j))) {
                    dp[i] = min(dp[i], dp[j] + i-j-(int)s.substr(j, i-j).length());
                } else {
                    dp[i] = min(dp[i], dp[j] + i-j);
                }
            }
        }
        
        return dp[n]; 
    }
};
