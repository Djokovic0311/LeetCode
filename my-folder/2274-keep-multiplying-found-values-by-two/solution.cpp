class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
    bool m[1001] = {};
    for (int n : nums)
        m[n] = true;
    while (original <= 1000 && m[original])
        original *= 2;
    return original;        
    }
};
