class Solution {
public:
    int countHomogenous(string s) {
        int MOD = 1e9+7;
        int n = s.length();
        int l = 0, r = 0;
        long long res = 0;

        while(l < n && r < n) {
            while(r < n && s[l] == s[r]) {
                r++;
            }
            res = ((long long )res +(long long ) (r-l+1) * (long long )(r-l)/ 2 % MOD) % MOD;
            if(r < n) {
                l = r;
            }
            else break;
        }

        return res;
    }
};
