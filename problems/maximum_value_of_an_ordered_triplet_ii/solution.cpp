class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        
        // 1. For each index i, find the maximum value on its right (maxRight[i]).
        vector<int> maxRight(n, -1);  // Initialize with -1, as 1 <= nums[i] <= 10^6
        int currentMax = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            maxRight[i] = currentMax;
            currentMax = max(currentMax, nums[i]);
        }
        
        long long result = LLONG_MIN;  // Initialize result to the smallest possible value
        
        int maxLeft = nums[0];
        
        // 2. For each index j, find the maximum value of (nums[i] - nums[j]) * maxRight[j] for all i on the left of j.
        for (int j = 1; j < n-1; j++) {
            if (maxRight[j] != -1) {  // Check if there's any element to the right of j
                result = max(result, (long long)(maxLeft - nums[j]) * maxRight[j]);
            }
            maxLeft = max(maxLeft, nums[j]);
        }
        
        // 3. Return the maximum value calculated in step 2. If the maximum value is negative, return 0.
        return max(result, 0LL);
    }
};
