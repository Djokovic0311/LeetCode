class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenExponent = false;
        bool seenDot = false;  
        int l = s.length();
        for(int i = 0; i < l;i++) {
            char curr = s[i];
            if(isdigit(curr)) {
                seenDigit = true;
            } else if(curr == '+' || curr == '-') {
                if(i > 0 && s[i-1] != 'e' && s[i-1] != 'E') {
                    return false;
                }
            } else if (curr == 'e' || curr == 'E') {
                if(seenExponent || !seenDigit) return false;
                seenExponent = true;
                seenDigit = false;
            } else if (curr == '.') {
                if(seenDot || seenExponent) return false;
                seenDot = true;
            } else return false;
        }

        return seenDigit;      
    }
};
