class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return -1;

        // Create prefix and suffix min arrays
        vector<int> leftMin(n, nums[0]);
        vector<int> rightMin(n, nums[n-1]);

        for (int i = 1; i < n; ++i) {
            leftMin[i] = min(leftMin[i-1], nums[i]);
        }
        for (int i = n-2; i >= 0; --i) {
            rightMin[i] = min(rightMin[i+1], nums[i]);
        }

        int result = INT_MAX;
        for (int j = 1; j < n-1; ++j) {
            if (leftMin[j-1] < nums[j] && rightMin[j+1] < nums[j]) {
                result = min(result, leftMin[j-1] + nums[j] + rightMin[j+1]);
            }
        }

        return (result == INT_MAX) ? -1 : result;        
    }
};
