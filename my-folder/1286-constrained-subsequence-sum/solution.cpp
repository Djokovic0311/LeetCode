class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n);
        dp[0] = nums[0];

        deque<int> q;
        q.push_back(0);

        int maxSum = nums[0];

        for (int i = 1; i < n; i++) {
            // Get the maximum value at the front of the deque
            if (q.front() < i - k) q.pop_front();

            // If the maximum value in the deque is positive, add it to nums[i]
            dp[i] = nums[i] + (dp[q.front()] > 0 ? dp[q.front()] : 0);

            // Maintain the deque in decreasing order
            while (!q.empty() && dp[i] >= dp[q.back()]) q.pop_back();

            q.push_back(i);

            maxSum = max(maxSum, dp[i]);
        }

        return maxSum;        
    }
};
