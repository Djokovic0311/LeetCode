class Solution {
public:
    bool isPerfectSquare(int num) {
        for(unsigned int i = 1; i * i <= num; i++) {
            if(i * i == num) return true;
        }
        return false;
    }
};