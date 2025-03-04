class Solution {
public:
    bool checkPowersOfThree(int n) {
        int remaining = 0;
        while(n >= 3) {
            remaining = n % 3;
            n /= 3;
            if(remaining == 2) return false;
        }
        if(n <= 1) return true;
        else return false;
    }
};
