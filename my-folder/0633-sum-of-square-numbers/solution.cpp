class Solution {
public:
    bool judgeSquareSum(int c) {
        for(double a = 0; a*a <= c; ++a){
            int b = sqrt(c - a*a);
            if(b*b == (c - a*a))
                return true;
        }
        return false;
    }
};
