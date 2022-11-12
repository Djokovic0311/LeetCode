class Solution {
public:
    double myPow2(double x, int n) {
        if(n == 0) return 1;
        double res = myPow2(x, n/2);
        if(n % 2 == 0)
            return res * res;
        else return res * res * x;
    }
    double myPow(double x, int n) {
        if(n < 0)
            x = 1/x;
        return myPow2(x, n);
    }
};