class Solution {
public:
    vector<int> findPeak(vector<vector<int>>& mat, int start_col, int end_col) {
        if (start_col > end_col) return {-1, -1};  // This shouldn't happen with the problem's constraints

        int mid_col = start_col + (end_col - start_col) / 2;
        int max_row = 0;
        for (int i = 0; i < mat.size(); i++) {
            if (mat[i][mid_col] > mat[max_row][mid_col]) {
                max_row = i;
            }
        }

        // Check if the maximum element in the middle column is a peak
        if ((mid_col == 0 || mat[max_row][mid_col] > mat[max_row][mid_col - 1]) && 
            (mid_col == mat[0].size() - 1 || mat[max_row][mid_col] > mat[max_row][mid_col + 1]) &&
            (max_row == 0 || mat[max_row][mid_col] > mat[max_row - 1][mid_col]) && 
            (max_row == mat.size() - 1 || mat[max_row][mid_col] > mat[max_row + 1][mid_col])) {
            return {max_row, mid_col};
        }

        // If not on the leftmost column and left neighbor is greater, search left
        if (mid_col > 0 && mat[max_row][mid_col] < mat[max_row][mid_col - 1]) {
            return findPeak(mat, start_col, mid_col - 1);
        } 
        // Otherwise, if not on the rightmost column, search right
        else if (mid_col < mat[0].size() - 1 && mat[max_row][mid_col] < mat[max_row][mid_col + 1]) {
            return findPeak(mat, mid_col + 1, end_col);
        }

        return {-1, -1};  // This should never be reached due to the problem's constraints
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
         return findPeak(mat, 0, mat[0].size() - 1);
    }
};
