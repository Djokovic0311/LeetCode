class Solution {
public:
    bool isMagicSquare(const vector<vector<int>>& grid, int row, int col, int size) {
        int sum = 0;
        for (int j = 0; j < size; ++j) {
            sum += grid[row][col + j]; // Calculate the sum of the first row to set a reference.
        }

        // Check rows and columns sum
        for (int i = 0; i < size; ++i) {
            int rowSum = 0, colSum = 0;
            for (int j = 0; j < size; ++j) {
                rowSum += grid[row + i][col + j];
                colSum += grid[row + j][col + i];
            }
            if (rowSum != sum || colSum != sum) return false; // If any row or column doesn't match the sum, return false.
        }

        // Check diagonals
        int diagSum1 = 0, diagSum2 = 0;
        for (int i = 0; i < size; ++i) {
            diagSum1 += grid[row + i][col + i];
            diagSum2 += grid[row + i][col + size - 1 - i];
        }
        if (diagSum1 != sum || diagSum2 != sum) return false; // If diagonals don't match the sum, return false.

        return true; // If all checks passed, it's a magic square.
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxSize = min(m, n); // The largest possible square's side length is the minimum of m and n.

        for (int size = maxSize; size > 0; --size) { // Start checking from the largest possible size.
            for (int row = 0; row <= m - size; ++row) {
                for (int col = 0; col <= n - size; ++col) {
                    if (isMagicSquare(grid, row, col, size)) {
                        return size; // If a magic square of this size is found, return its size.
                    }
                }
            }
        }
        return 1; 

    }
};
