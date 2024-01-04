class Solution {
public:
    void backtracking(vector<string>& res, string s, unordered_set<string>& st, vector<string>& tmp) {
        if(s.length() == 0) {
            string sent = "";
            for(string t : tmp) {
                if(sent == "") {
                    sent += t;
                } else {
                    sent += " ";
                    sent += t;
                }
            }
            res.push_back(sent);
            return;
        }

        for(int i = 0; i < s.length(); i++) {
            string sub = s.substr(0, i+1);
            if(st.count(sub)) {
                tmp.push_back(sub);
                backtracking(res, s.substr(i+1), st, tmp);
                tmp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res, tmp;
        unordered_set<string> word_Set(wordDict.begin(),wordDict.end());
        backtracking(res, s, word_Set, tmp);
        return res;
    }
};
