class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<vector<bool>> visited(n , vector<bool>(n,false));
        
        queue<int> q;
        q.push(1);
        visited[n-1][0]=true;
        int steps=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)  /// checking levels for smallest steps , similar to shortest path 
            {
                int currpos = q.front();
                if(currpos==n*n)
                        return steps;
                q.pop(); 
                for(int i=1;i<=6;i++)    /// a dice can get 1 to number 6 
                {
                    int nextpos=currpos+i;
                    if(nextpos>n*n)
                        break;
                    int r = n - (nextpos-1)/n -1;   // getting row of board matrix
                    int c = (nextpos-1)%n;           // getting column of board matrix
                    if(r%2 == n%2)      // this step is imp because the value after n will come just above n like 7 will
                        c = n-c-1; // come just above 6 and not above 1  , if we are given in other format we can skip this
                    if(!visited[r][c])
                    {
                        visited[r][c]=true;
                        if(board[r][c]!=-1)
                            q.push(board[r][c]);  // if it is ladder or snake push that value else just push next position
                        else
                            q.push(nextpos);
                    }
                }
            }
            steps++;
        }
        return -1;                
    }
};
