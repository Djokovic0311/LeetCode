class Solution {
public:
    int nextGreaterElement(int n) {
        long res = 0; string dig = to_string(n);
        next_permutation(dig.begin(),dig.end());
        res = stol(dig);
        if(res <= n || res > INT_MAX) return -1;
        return res;
    }
};
