class Solution {
public:
    bool isPowerOfThree(int n) {
    double res=log10(n)/log10(3);
    return (n > 0 ) && (res == (int)res);        
    }
};
