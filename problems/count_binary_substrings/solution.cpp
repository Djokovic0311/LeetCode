class Solution {
public:
    int countBinarySubstrings(string s) {
        int cur = 0, prev = 0;
        int ans = 0;
        int n = s.length();

        for(int i = 0; i < n; i++) {
            if(i && s[i] == s[i-1]) {
                cur++;
            }
            else {
                prev = cur;
                cur = 1;
                
            }
            if(cur <= prev)
                ans++;
        }
        return ans;
    }
};