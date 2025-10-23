class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length() > 2) {
            string tmp = "";
            for(int i = 1; i < s.length(); i++) {
                tmp += ((s[i] - '0') + (s[i-1] - '0')) % 10;
            }
            s = tmp;
        }
        return s[0] == s[1];
    }
};
