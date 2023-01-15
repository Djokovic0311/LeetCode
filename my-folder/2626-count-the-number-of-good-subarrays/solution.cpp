class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0;
        unordered_map<int, int> count;
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            k -= count[nums[j]]++;
            while (k <= 0)
                k += --count[nums[i++]];
            res += i;
        }
        return res;
    }
};
