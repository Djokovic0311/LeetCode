class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int top = 0, bottom = n-1, left = 0, right = n-1;
        int val = 1,direction=1;
        while(left<=right && top<=bottom)
        {
            if(direction == 1)    
            {   
                for(int i=left;i<=right;i++)
                {
                    res[top][i]=val++;
                }
                top++;
                direction=2;
            }
            else if(direction == 2)
            {
                for(int i = top;i<=bottom;i++)
                {
                    res[i][right]=val++;
                }
                right--;
                direction = 3;
            }
            else if(direction == 3)
            {
                for(int i = right;i>=left;i--)
                {
                    res[bottom][i]=val++;
                }
                bottom--;
                direction=4;
            }
            else if(direction == 4)
            {
                for(int i=bottom;i>=top;i--)
                {
                    res[i][left]=val++;
                }
                left++;
                direction = 1;
            }
        }
        return res;
    }
};