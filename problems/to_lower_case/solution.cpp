class Solution {
public:
    string toLowerCase(string s) {
        for(int i = 0; i < s.length(); i++) {
            if(s[i] >= 'A' && s[i] <= 'Z') s[i] = 'a'+ s[i] -'A';
        }
        return s;
    }
};