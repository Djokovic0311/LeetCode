class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int m=board.size(),n=board[0].size();
		int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
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
                for(int i = 0; i < 4; i++) {
                    int nr = r + dx[i], nc = c + dy[i];
                    if(nr < m && nr >= 0 && nc < n && nc >= 0 && board[nr][nc] == 'O') {
                        board[nr][nc]='.';
                        q.push({nr,nc});
                    }
                }
            }
        }
		//all the unsorrounded O's are re-entered
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                board[i][j]=board[i][j]=='.'?'O':'X';               
    }
};
