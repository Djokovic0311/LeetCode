class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        string s = to_string(num);
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(num % (s[i]-'0') == 0) res++;
        }
        return res;
    }
};
