class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        nums.insert(nums.begin(),lower);
        nums.insert(nums.end(), upper);
        
        for (int i = 0; i < nums.size() - 1; i++) {
            int start = nums[i] + 1;
            int end = nums[i + 1] - 1;
            
            // If nums[i] == lower, range should be [nums[i], nums[i + 1] - 1],
            // instead of [nums[i] + 1, nums[i + 1] - 1]
            // [1,3,8] -> [0,1,3,8,10], first range should be [0]
            if (i == 0) {
                start = lower;
            }
            
            // If nums[i + 1] == upper, range should be [nums[i] + 1, nums[i + 1]],
            // instead of [nums[i] + 1, nums[i + 1] - 1]
            // [1,3,8] -> [0,1,3,8,10], last range should be [9,10]
            if (i == nums.size() - 2) {
                end = nums[i + 1];
            }
            
            // general cases
            if (start < end) {
                string str = to_string(start) + "->" + to_string(end);
                res.push_back(str);
            } else if (start == end) {
                res.push_back(to_string(start));
            }
        }
        
        return res;
    }
};