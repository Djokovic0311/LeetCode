class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;

        int zero = 0;
        int one = 0;
        int two = 1;

        // Compute using derived equations
        for (char thing : corridor) {
            if (thing == 'S') {
                zero = one;
                swap(one, two);
            } else {
                two = (two + zero) % MOD;
            }
        }

        // Return the result
        return zero;
    }
};
