class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long c1 = 0, c2 = 0;
        long long res = 0;
        int n = text.length();
        for(int i = 0; i < n; i++) {
            if(text[i] == pattern[0]) c1++;
            if(text[i] == pattern[1]) { 
                res += c1;
                c2++;
            }
        }
        res += max(c1,c2);
        if(pattern[0] == pattern[1]) {
            return (c1 * (c1 - 1)/2) + c1;
        }
        return res;
    }
};
