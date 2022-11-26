class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> onesRow(m,0), onesCol(n,0), zerosRow(m,0), zerosCol(n,0);
        vector<vector<int>> diff(m, vector<int>(n,0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    zerosRow[i]++;
                }
                else {
                    onesRow[i]++;
                }
            }
        }
        
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                if(grid[i][j] == 0) {
                    zerosCol[j]++;
                }
                else {
                    onesCol[j]++;
                }
            }
        }
        
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                diff[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }
        return diff;
    }
};
