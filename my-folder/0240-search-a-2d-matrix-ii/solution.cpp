class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i=0;
        int j=n-1;
        while(i<m && j>=0){
            if(matrix[i][j]==target) // target found
                return true;
            else if(matrix[i][j]>target) 
                --j;
            else 
                ++i; // increase the row index
        }
        return false; // target not found
    }
};
