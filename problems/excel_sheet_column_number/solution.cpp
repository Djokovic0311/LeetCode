class Solution {
public:
    int titleToNumber(string s) {
        long res = 0;
        int pos = 0;
        while (pos < s.size()) {
            res = res * 26 + s[pos] - '@';
            pos++;
        }
        return res;       
    }
};