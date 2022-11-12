class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, need = 0;
        int n = nums.size();
        for (int a: nums) {
            res += max(need - a, 0);
            need = max(a, need)+1;
        }
        return res;
    }
};