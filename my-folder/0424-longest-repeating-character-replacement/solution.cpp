class Solution {
public:
    int characterReplacement(string s, int k) {
        int chars[26] = {0};
        int n = s.length();
        int l = 0, r = 0;
        int max_freq = 0;
        while(r < n) {
            chars[s[r]-'A']++;
            max_freq = max(max_freq, chars[s[r]-'A']);
            r++;
            if(r-l-max_freq > k) {
                chars[s[l]-'A']--;
                l++;
            }

        }
        return r-l;
    }
};
