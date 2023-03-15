class Solution {
public:
    int longestSubsequence(string s, int k) {
        int totalZero = 0;
        int usedOne = 0;
        int base = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (base > k) {
                if (s[i] == '0') {
                    totalZero++;
                }
                continue;
            }
            if (s[i] == '0') {
                totalZero++;
                base *= 2;
            } else {

                if (k >= base) {
                    k -= base;
                    usedOne++;
                    base *= 2;
                }
            }
        }
        return totalZero + usedOne;        
    }
};
