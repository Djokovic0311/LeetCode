class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> result(r,vector<int>(c));
        queue<int> total;
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                total.push(mat[i][j]);
            }
        }
        if(r * c == total.size()){
            for(int i = 0; i < r; i++) {
                for(int j = 0; j < c; j++) {
                    result[i][j] = total.front();
                    total.pop();
                }
            }            
            return result;
        }

        else return mat;
    }
};