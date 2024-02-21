class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if ((m == 0) || (n == 0)) 
            return 0;
        
        if (m == n) 
            return m;
        
        if (n-m == 1) 
            return m&n;
        
        if ((int)log2(m) != (int)log2(n)) 
            return 0;
        
        else 
        {
            int res = m;
            for (long long i=m+1; i<=n;i++)
                res &= i;
                
            return res;
        }
    }
};
