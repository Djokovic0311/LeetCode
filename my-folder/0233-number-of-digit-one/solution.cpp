class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        for(long long i = 1; i <= n; i*=10) {
            long long divider = i * 10;
            count += (n / divider) * i + min(max(n % divider - i + 1, 0ll), i);
        }
        return count;
    }
};
