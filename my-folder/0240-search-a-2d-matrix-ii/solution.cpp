class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if(m == 0 || n == 0) return false;
        int row = m-1, col = 0;
        while(col < n && row >= 0) {
            if(matrix[row][col] > target) {
                row -= 1;
            } else if(matrix[row][col] < target) {
                col+=1;
            } else return true;
        }

        return false;
    } 
};
