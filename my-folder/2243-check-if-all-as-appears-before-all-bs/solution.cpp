class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        int i = 0;
        while(s[i] == 'a') i++;
        for(int j = i; j < n; j++) {
            if(s[j] != 'b') return false;
        }
        return true;
    }
};
