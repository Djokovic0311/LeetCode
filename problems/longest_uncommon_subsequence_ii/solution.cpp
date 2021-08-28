class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int res = -1, j = 0, n = strs.size();
        for (int i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (i == j) continue;
                if (checkSubs(strs[i], strs[j])) break;
            }
            if (j == n) res = max(res, (int)strs[i].size());
        }
        return res;
    }
    int checkSubs(string subs, string str) {
        int i = 0;
        for (char c : str) {
            if (c == subs[i]) ++i;
            if (i == subs.size()) break;
        } 
        return i == subs.size();
    }
};