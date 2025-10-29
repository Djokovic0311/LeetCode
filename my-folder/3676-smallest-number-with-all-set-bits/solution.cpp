class Solution {
public:
    int smallestNumber(int n) {
        int num = 2;
        while(num - 1 < n) {
            num *= 2; 
        }
        return num-1;
    }
};
