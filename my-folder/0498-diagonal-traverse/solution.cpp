class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res(m*n);
        if(m == 0 || n == 0) return res;
        int row = 0, col = 0;
        int direction =1;
        int r = 0;
        while(row < m && col < n) {
            res[r++] = mat[row][col];
            int nr = row + (direction == 1? -1 : 1);
            int nc = col + (direction == 1 ? 1 : -1);
            if(nr < 0 || nr == m || nc < 0 || nc == n) {
                if(direction == 1) {
                    row += (col == n-1 ? 1 : 0);
                    col += (col < n-1 ? 1 : 0);
                } else {
                    col += (row == m-1 ? 1 : 0);
                    row += (row < m-1 ? 1 : 0);
                }
                direction = 1 - direction;
            } else {
                row = nr;
                col = nc;
            }
            
        }
        return res;
    }
};
