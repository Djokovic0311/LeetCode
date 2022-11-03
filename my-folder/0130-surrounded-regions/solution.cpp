class Solution {
public:
    void solve(vector<vector<char>>& board) {
         queue<pair<int,int>> q;
        int m=board.size(),n=board[0].size();
		
		//Getting boundary O's
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O') board[i][0]='.',q.push({i,0});
            if(board[i][n-1]=='O') board[i][n-1]='.',q.push({i,n-1});
        }
        for(int i=1;i<n-1;i++)
        {
            if(board[0][i]=='O') board[0][i]='.',q.push({0,i});
            if(board[m-1][i]=='O') board[m-1][i]='.',q.push({m-1,i});
        }
		
		//BFS
        while(q.size())
        {
            int sz=q.size();
            while(sz--)
            {
                auto p=q.front();q.pop();
                int r=p.first,c=p.second;
                 if(r+1<m) if(board[r+1][c]=='O') board[r+1][c]='.',q.push({r+1,c});
                 if(r-1>=0) if(board[r-1][c]=='O') board[r-1][c]='.',q.push({r-1,c});
                 if(c+1<n) if(board[r][c+1]=='O') board[r][c+1]='.',q.push({r,c+1});
                 if(c-1>=0) if(board[r][c-1]=='O') board[r][c-1]='.',q.push({r,c-1});    
            }
        }
		//all the unsorrounded O's are re-entered
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                board[i][j]=board[i][j]=='.'?'O':'X';        
    }
};
