class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        bool crush = true;
        while(crush)
        {
            crush = false;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    int curr = abs(board[i][j]);
                    if(!curr)
                        continue;
                    if(i<n-2 && abs(board[i+1][j])==curr && abs(board[i+2][j])==curr)
                    {
                        crush = true;
                        int counter = i;
                        while(counter<n && abs(board[counter][j])==curr)
                            board[counter++][j] = -curr;
                    }
                    if(j<m-2 && abs(board[i][j+1])==curr && abs(board[i][j+2])==curr)
                    {
                        crush = true;
                        int counter = j;
                        while(counter<m && abs(board[i][counter])==curr)
                            board[i][counter++] = -curr;
                    }
                }
            }
            if(crush)
            {
                for(int j=0; j<m; j++)
                {
                    int movedown = n-1;
                    for(int i=n-1; i>=0; i--)
                    {
                        if(board[i][j]>0)
                            board[movedown--][j] = board[i][j];
                    }
                    for(int k=movedown; k>=0; k--)
                        board[k][j]=0;
                }
            }
        }
        return board;
    }
};
