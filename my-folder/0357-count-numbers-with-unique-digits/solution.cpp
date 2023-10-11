class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;

        int total = 10;  // for n = 1
        int base = 9;
        int curr = 9;

        for (int i = 2; i <= n && i <= 10; ++i) {  // i <= 10 because after 10 digits there's no way to have unique digits
            curr *= (11 - i);  // 11-i gives the correct multiplier (9 for first, 8 for second, 7 for third, and so on...)
            total += curr;
    }

    return total;        
    }
};
