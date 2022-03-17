class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowsize=matrix.size(); 
        int columnsize=matrix[0].size(); 
        vector<int>rowmarker(rowsize,1);
        vector<int>columnmarker(columnsize,1); 
        for(int i=0;i<rowsize;i++)
        {
            for(int j=0;j<columnsize;j++)
            {
                if(matrix[i][j]==0)
                {
                    rowmarker[i]=0; 
                    columnmarker[j]=0;
                }
            }
        } 
        for(int i=0;i<rowsize;i++)
        {
            for(int j=0;j<columnsize;j++)
            {
                if(rowmarker[i]==0 or columnmarker[j]==0)
                    matrix[i][j]=0;
             }
        }
        
    
    }
};