class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, size_t> tmp;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (tmp.count(target - nums[i])) {
                return {int(tmp[target - nums[i]]), int(i)};
            }
            tmp[nums[i]] = i;
        }
        return {int(nums.size()), int(nums.size())};        
    }
};
