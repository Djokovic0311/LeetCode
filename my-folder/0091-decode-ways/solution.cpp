class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(s[0] == '0') return 0;
        int one_back = 1, two_back = 1;
        for(int i = 1; i < n; i++){
            int current = 0;
            if (s[i] != '0') {
                current = one_back;
            }
            if((s[i-1] == '1') || (s[i-1] == '2' && s[i] >= '0' && s[i] <= '6')) {
                current += two_back;
            }

            two_back = one_back;
            one_back = current;
        }

        return one_back;
    }
};
