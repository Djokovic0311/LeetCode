class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                // Check if removing subarray [i, j] makes the array strictly increasing
                if (isStrictlyIncreasing(nums, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }

private:
    bool isStrictlyIncreasing(const vector<int>& nums, int start, int end) {
        int prev = INT_MIN;
        for (int i = 0; i < start; ++i) {
            if (nums[i] <= prev) return false;
            prev = nums[i];
        }
        for (int i = end + 1; i < nums.size(); ++i) {
            if (nums[i] <= prev) return false;
            prev = nums[i];
        }
        return true;
    }
};
