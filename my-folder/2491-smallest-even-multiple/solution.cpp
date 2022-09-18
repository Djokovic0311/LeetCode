class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n==1) return 2;
        if(n % 2 == 1) return 2 * n;
        else return n;
    }
};
