class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return grid[0][0]; // If there's only one element, return it.
        
        // Initialize dp array with the first row, since the first row of dp is the same as the first row of the grid.
        vector<vector<int>> dp = grid;
        
        // Start from the second row
        for (int r = 1; r < n; r++) {
            // Find two smallest values in the previous row for non-zero shift.
            int min1 = INT_MAX, min2 = INT_MAX;
            int min1_idx = -1;
            for (int c = 0; c < n; c++) {
                if (dp[r-1][c] < min1) {
                    min2 = min1;
                    min1 = dp[r-1][c];
                    min1_idx = c;
                } else if (dp[r-1][c] < min2) {
                    min2 = dp[r-1][c];
                }
            }

            // Calculate dp values for the current row.
            for (int c = 0; c < n; c++) {
                // If the current column had the smallest in previous row, use the second smallest.
                if (c == min1_idx) {
                    dp[r][c] = min2 + grid[r][c];
                } else {
                    dp[r][c] = min1 + grid[r][c];
                }
            }
        }

        // The answer is the minimum value in the last row of the dp array.
        return *min_element(dp[n-1].begin(), dp[n-1].end());       
    }
};
