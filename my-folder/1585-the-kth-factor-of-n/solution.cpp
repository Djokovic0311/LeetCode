class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> divisors;
        int sqrtN = (int)sqrt(n);
        for (int x = 1; x < sqrtN + 1; ++x) {
            if (n % x == 0) {
                --k;
                divisors.push_back(x);
                if (k == 0) {
                    return x;    
                }    
            }    
        }
        
        // If n is a perfect square, skip the duplicate in the divisor list
        if (sqrtN * sqrtN == n) {
            ++k;    
        }
        
        int nDiv = divisors.size();
        return (k <= nDiv) ? n / divisors[nDiv - k] : -1;
    }
};
