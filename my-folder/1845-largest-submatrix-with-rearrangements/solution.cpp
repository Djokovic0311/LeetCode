class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] != 0 && i > 0) {
                    matrix[i][j] += matrix[i-1][j];
                }
            }
            vector<int> currentRow = matrix[i];
            sort(currentRow.begin(), currentRow.end(), greater());
            for(int k = 0; k < n; k++) {
                res = max(res, currentRow[k] * (k+1));
            }
        }

        return res;
    }
};
