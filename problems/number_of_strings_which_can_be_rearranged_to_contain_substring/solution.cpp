class Solution {
private:
    int powerMod(int x, int n, int mod) {
        int result = 1, p = x % mod;
        while (n) {
            if (n & 1) {
                result = (1LL * result * p) % mod;
            }
            p = (1LL * p * p) % mod;
            n >>= 1;
        }
        return result;
    }
    
public:
    int stringCount(int n) {
        int count = 0, mod = 1e9 + 7;
        count = (count + powerMod(26, n, mod)) % mod;
        count = (count - (n + 75LL) * powerMod(25, n - 1, mod)) % mod;
        count = (count + (2LL * n + 72) * powerMod(24, n - 1, mod)) % mod;
        count = (count - (n + 23LL) * powerMod(23, n - 1, mod)) % mod;
        return (count % mod + mod) % mod;
    }
};