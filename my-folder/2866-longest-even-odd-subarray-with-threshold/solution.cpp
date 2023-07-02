class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
    int max_length = 0;
    for (int l = 0; l < nums.size(); ++l) {
        if (nums[l] % 2 == 0 && nums[l] <= threshold) {
            int r = l;
            while (r + 1 < nums.size() && nums[r] % 2 != nums[r + 1] % 2 && nums[r + 1] <= threshold) {
                ++r;
            }
            max_length = max(max_length, r - l + 1);
        }
    }
    return max_length;      
    }
};
