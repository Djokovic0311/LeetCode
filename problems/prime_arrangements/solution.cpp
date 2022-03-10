class Solution {
    const long mod = 1000000007;
    long factorial(int n, int prime = 2, long start = 1) {
        long a = start;
        for (int i = prime; i <= n; i++) {
            a *= i;
            if (a >= mod) a %= mod;
        }
        return a;
    }
public:
    int numPrimeArrangements(int n) {
        int primes[] {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
        int i = 0;
        for (; i < 25 && primes[i] <= n; i++);
        int minNum = i, rest = n - i;
        if (n < (i << 1)) swap(minNum, rest);
        
        long a = factorial(minNum), b = factorial(rest, minNum + 1, a);
        return (int)(a * b % mod);
    }
};