class Solution {
    public int maximumXorProduct(long a, long b, int n) {
        final int MOD = 1000000007;
        long x = 0;

        for (int i = n - 1; i >= 0; i--) {
            long bit = (long) 1 << i;
            if((bit & a) == (bit & b)) {
                a = a | bit;
                b = b | bit;
            }
            else {
                if (a > b) {
                    long temp = a;
                    a = b;
                    b = temp;
                }
                a = a | bit;
                b = b & (~bit);
            }


        }

        
        return (int)((a % MOD) * (b % MOD) % MOD);   
    }
}
