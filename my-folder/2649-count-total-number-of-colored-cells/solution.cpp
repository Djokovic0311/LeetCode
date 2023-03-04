class Solution {
public:
    long long coloredCells(int n) {
        long long res = 1;
        if(n == 1) return 1;
        for(long long i = 2; i <= n; i++) {
            res += 4 * (i-1);
        }
        
        return res;
    }
};
