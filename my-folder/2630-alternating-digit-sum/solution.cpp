class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        int l = s.length();
        int res = 0;
        int sig = 1;
        
        for(int i = 0; i < l; i++) {
            res += sig * (s[i]-'0');
            sig *= -1;
        }
        
        return res;
    }
};
