class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int n = s.length()-1;
        while(n>0) {
            if(s[n] == ' ') n--;
            else break;
        }
        for(int i = n; i >=0; i--) {
            if(s[i]!=' ') res++;
            else break;
        }
        return res;
    }
};
