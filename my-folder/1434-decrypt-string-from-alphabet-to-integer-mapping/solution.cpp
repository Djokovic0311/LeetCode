class Solution {
public:
    string freqAlphabets(string s) {
        int n = s.length();
        string res = "";
        for(int i = 0; i < n; i++) {
            if(i+2 < n && s[i+2] == '#') {res += ('a' + 10 * (s[i]-'0') + (s[i+1]-'0'-1)); i += 2;}
            else res += 'a' + (s[i]-'0'-1);
        }
        return res;
    }
};
