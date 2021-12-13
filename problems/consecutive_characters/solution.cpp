class Solution {
public:
    int maxPower(string s) {
        int res = 0, i = 0, j, n = s.length();
        char cur = s[0];
        while(i < n) {
            j = i + 1;
            while(j < n && s[j] == s[i]) j++;
            res = max(res, j-i);
            i = j;
        }
        return res;
    }
};