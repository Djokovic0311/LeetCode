class Solution {
public:
    bool isSameAfterReversals(int num) {
        string origin = to_string(num);
        int n = origin.length();
        return n == 1 || origin[n-1] != '0';  
    }
};