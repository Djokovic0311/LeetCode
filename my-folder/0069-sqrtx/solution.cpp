class Solution {
public:
    int mySqrt(int x) {
        unsigned int i;
        for(i = 0; i * i <= x; i++) ;
        return i-1;        
    }
};
