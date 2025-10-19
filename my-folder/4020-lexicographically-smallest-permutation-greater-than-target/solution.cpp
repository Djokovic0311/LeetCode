class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        
        string res(n, '*');

        auto fillGreedy = [&](int pos, vector<int>& cc, string& out) {
            for (int c = 0; c < 26; ++c) {
                while (cc[c] > 0) {
                    out[pos++] = char('a' + c);
                    --cc[c];
                }
            }
        };

        function<bool(int,bool,vector<int>&)> dfs = [&](int i, bool tight, vector<int>& cc) -> bool {
            if (i == n) {
                // Only valid if strictly greater (not fully equal)
                return !tight;
            }

            if (tight) {
                int t = target[i] - 'a';

                // Option 1: match target[i]
                if (cc[t] > 0) {
                    --cc[t];
                    res[i] = target[i];
                    if (dfs(i + 1, true, cc)) return true;
                    ++cc[t]; // backtrack
                }

                // Option 2: place smallest letter > target[i]
                for (int c = t + 1; c < 26; ++c) if (cc[c] > 0) {
                    --cc[c];
                    res[i] = char('a' + c);
                    auto tmp = cc;  // copy for filling suffix
                    fillGreedy(i + 1, tmp, res);
                    return true;
                }

                return false;
            } else {
                // Already greater — just fill remaining greedily
                auto tmp = cc;
                fillGreedy(i, tmp, res);
                return true;
            }
        };

        if (dfs(0, true, cnt)) return res;
        return "";  
    }
};
