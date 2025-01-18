class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        int l = text.length();
        int n = words.size();
        vector<vector<int>> res;
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < n; j++) {
                string subword = text.substr(i, words[j].length());
                if(subword == words[j]) {
                    res.push_back({i, i+(int)words[j].length()-1});
                }
            }
        }
        return res;
    }
};
