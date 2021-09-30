class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int r = M.size(); 
        int c = M[0].size();
        
        int dr[9] = {0,0, 0, 1,1,-1, 1,-1,-1}; 
        int dc[9] = {0,1,-1,-1,1, 0, 0,-1, 1}; 
        vector<vector<int> > A (r, vector<int>(c,0) ); 
        
        for(int i = 0 ; i < r ; i++) //for each row
        {
            for(int j = 0 ; j < c ; j++) //for each col
            {
                int count = 0; 
                int sum = 0; //sum the values of neighbours
                
                for(int d = 0 ; d < 9 ; d++) 
                {
                    if(i+dr[d] >= 0 && j+dc[d] >= 0 && i+dr[d] < r && j+dc[d] < c)
                    {
                        sum += M[i+dr[d]][j+dc[d]]; //increment sum
                        count++; //increment count
                    }    
                }
                
                A[i][j] = sum/count; // take average and store in ans vector
            }
        }
        
        return A;        
    }
};
