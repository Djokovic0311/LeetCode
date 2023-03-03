class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int m = haystack.length();
        if(m == n) return needle == haystack ? 0 : -1;
        for(int i = 0; i <= m-n; i++) {
            if(haystack.substr(i,n) == needle)
                return i;
        }

        return -1;
    }
};
