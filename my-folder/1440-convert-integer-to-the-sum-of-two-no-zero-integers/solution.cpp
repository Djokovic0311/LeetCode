class Solution {
public:
    bool no_zero(int n) {
        while (n>0)
        {
            if (n % 10 == 0)
                return false;
            n /= 10;
        }
        return true;
    }
    
    
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;
        int i=1;
        while (i<n)
        {
            if ((no_zero(i)) && (no_zero(n-i)))
            {
                res.push_back(i);
                res.push_back(n-i);
                return res;
            }  
            i++;
        }
        return res;
    }
};
