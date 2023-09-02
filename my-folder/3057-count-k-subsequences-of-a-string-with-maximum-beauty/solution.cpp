class Solution {
private:
    const int MOD = 1e9 + 7;
    
    int mod_pow(int base, int exp, int mod) {
        int result = 1;
        while (exp > 0) {
            if (exp & 1) result = (long long)result * base % mod;
            base = (long long)base * base % mod;
            exp >>= 1;
        }
        return result;
    }
    
    int mod_inv(int n, int mod) {
        return mod_pow(n, mod - 2, mod);
    }
    
    int comb(int n, int r) {
        if (r == 0 || n == r) return 1;
        if (r == 1) return n;
        
        long long numerator = 1, denominator = 1;
        for (int i = 0; i < r; i++) {
            numerator = (numerator * (n - i)) % MOD;
            denominator = (denominator * (i + 1)) % MOD;
        }
        
        return (numerator * mod_inv(denominator, MOD)) % MOD;
    }

public:
    int countKSubsequencesWithMaxBeauty(std::string s, int k) {
        std::vector<int> f(26, 0);
        for (char c : s) {
            f[c - 'a']++;
        }
        std::sort(f.begin(), f.end(), std::greater<int>());
        
        if (k > 26 || f[k-1] == 0) return 0;
        
        int t = f[k-1];
        int I = 0;
        
        for (int i = 0; i < 26; i++) {
            if (f[i] == t) I++;
        }
        
        long long ans = 1;
        int need = 0;
        for (int i = 0; i < k; i++) {
            if (f[i] != t) {
                ans = (ans * f[i]) % MOD;
            } else {
                need++;
            }
        }
        
        ans = (ans * comb(I, need)) % MOD;
        ans = (ans * mod_pow(t, need, MOD)) % MOD;

        return ans;
    }
};
