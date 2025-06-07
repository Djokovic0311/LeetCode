class Solution {
public:
    string clearStars(string s) {
        int l = s.length();
        vector<stack<int>> cnt(26);
        string res;
        for(int i = 0; i < l ; i++) {
            if(s[i] != '*') {
                cnt[s[i]-'a'].push(i);
            } else {
                for(int j = 0; j < 26; j++) {
                    if(!cnt[j].empty()) {
                        s[cnt[j].top()] = '*';
                        cnt[j].pop();
                        break;
                    }
                }
            }
        }
        for(char c: s) {
            if(c != '*') {
                res.push_back(c);
            }
        }
        return res;
    }
};
