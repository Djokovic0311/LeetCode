class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int res = 0;
        int count1 = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                while(i+1 < n && s[i+1] == '0') {
                    i++;
                }
                res += count1;
            } else {
                count1++;
            }
        }
        return res;
    }
};
