class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = 0;
        while(start > 0 || goal > 0) {
            res += (start % 2) ^ (goal % 2);
            start /= 2;
            goal /= 2;
            
        }
        return res;
    }
};