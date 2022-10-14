class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), [](const string &l, const string &r) { return l.size() < r.size(); });
        int res = 1;
        for(string w : words) {
            dp[w] = 1;
            for(int i = 0; i < w.length(); i++) {
                string prev = w.substr(0, i) + w.substr(i + 1);
                if(dp.find(prev) != dp.end()) {
                    dp[w] = max(dp[w], dp[prev] + 1);
                    res = max(res, dp[w]);
                }
            }
        }
        return res;
    }
};