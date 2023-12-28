class Solution {
public:
    int divide(int dividend, int divisor) {
        int HALF_INT_MIN = -1073741824;
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }
        int quotient = 0;
        while(divisor >= dividend) {
            int powerOfTwo = -1;
            int value = divisor;
            while(value > HALF_INT_MIN && value + value >= dividend) {
                value += value;
                powerOfTwo += powerOfTwo;
            }
            quotient += powerOfTwo;
            dividend -= value;
        }
        
        if (negatives != 1) {
            return -quotient;
        }
        return quotient;
    }
};
