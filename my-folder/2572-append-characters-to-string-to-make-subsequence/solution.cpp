class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = s.length(),n = t.length();
        int res = n;
        
        int i = 0, j = 0;
        for(; i < m; i++) {
            if(j < n && s[i] == t[j]) {
                j++;
            }
        }
        // cout << j << endl;
        return n-j;
    }
};
