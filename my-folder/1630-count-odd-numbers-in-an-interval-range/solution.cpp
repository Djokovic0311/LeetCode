class Solution {
public:
    int countOdds(int low, int high) {
        int res = (low % 2 == 1 || high % 2 == 1)? (high-low) / 2 +1: (high-low) /2;
        return res;
    }
};
