class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int res = 0;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                open++;
            } else {
                if(i < n-1 && s[i+1] == ')') {
                    if(open > 0) {
                        open--;
                    } else {
                        res++;
                    }
                    i++;
                } else {
                    if(open > 0) {
                        open--;
                        res++;
                    } else {
                        res += 2;
                    }
                }
            }
        }
        res += open*2;
        return res;
    }
};
