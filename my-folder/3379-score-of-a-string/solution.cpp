class Solution {
public:
    int scoreOfString(string s) {
        int res = 0;
        int l = s.length();
        for(int i = 0; i < l-1; i++) {
            res += abs(s[i] - s[i+1]);
        }

        return res;
    }
};
