class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        nums.insert(nums.begin(),lower);
        nums.insert(nums.end(), upper);

        for (int i = 0; i < nums.size() - 1; i++) {
            int start = nums[i] + 1;
            int end = nums[i + 1] - 1;
            
            if (i == 0) {
                start = lower;
            }
            
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
