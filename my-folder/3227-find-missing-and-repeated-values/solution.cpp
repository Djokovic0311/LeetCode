class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq(n * n + 1, 0);
        vector<int> ans(2, 0);

        // Flatten the matrix and count frequencies
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                freq[grid[i][j]]++;
            }
        }

        // Find repeating and missing numbers
        for (int i = 1; i <= n * n; ++i) {
            if (freq[i] == 2) ans[0] = i;  // Repeating
            if (freq[i] == 0) ans[1] = i;  // Missing
        }

        return ans;        
    }
};
