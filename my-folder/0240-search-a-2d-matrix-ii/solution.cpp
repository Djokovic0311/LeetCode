class Solution {
public:

    bool search(int left, int up, int right, int down, int target, vector<vector<int>>& matrix) {

        if(left > right || up > down) return false;
        else if (target < matrix[up][left] || target > matrix[down][right]) return false;
        int mid = left + (right-left)/2;
        int row = up;
        // Locate `row` such that matrix[row-1][mid] < target < matrix[row][mid]
        while(row <= down && matrix[row][mid] <= target) {
            if(matrix[row][mid] == target) return true;
            row++;
        }
        return search(left, row, mid-1, down, target, matrix) || search(mid+1,up,right,row-1, target, matrix);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if(m == 0 || n == 0) return false;

        return search(0,0,n-1, m-1, target, matrix);
    }
};
