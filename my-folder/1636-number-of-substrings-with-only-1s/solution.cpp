class Solution {
public:
    int numSub(string s) {
        int MOD = 1e9+7;
        int n = s.length();
        int i = 0, j = 0;
        int res = 0;
        while(i < n && j < n) {
            while(s[i] == '0') i++;
            j = i;
            while(s[j] == '1') j++;
            int l = (j-i);
            res += (long long) l * (l+1) % MOD / 2 % MOD;
            i = j;
        }
        return res;
    }
};
