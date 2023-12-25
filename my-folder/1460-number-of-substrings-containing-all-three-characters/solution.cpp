class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count = {0,0,0};
        int n = s.length();
        int l = 0, r = 0;
        int res= 0;
        while(r < n) {
            count[s[r]-'a']++;
            while(count[0] && count[1] && count[2]) {
                count[s[l++]-'a']--;
            }
            res += l;
            r++;
        }
        return res;
    }
};
