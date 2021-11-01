class Solution {
public:
    bool isSafe(int i, int j, int m, int n){
        return (i>=0 && i<m && j>=0 && j<n);
    }
	// Checks whether the indices are present at the border of the matrix.
    bool isBorder(int i, int j, int m, int n){
        return (i==0 || i==m-1 || j==0 || j==n-1);
    }
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return;
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;
        vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0, 1}, {0, -1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && isBorder(i,j,m,n)){
                    board[i][j] = '.';
                    q.push(make_pair(i,j));                    
                }
            }
        }
        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();
            for(int i=0;i<dir.size();i++){
                int x = temp.first + dir[i].first;
                int y = temp.second + dir[i].second;

                if(isSafe(x,y,m,n) && !isBorder(x,y, m,n) && board[x][y]=='O'){
                    board[x][y]= '.';
                    q.push(make_pair(x,y));
                }
            }
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
			    // Just convert the remaining 'O' into 'X' as they are not connected to any border 'O'.
                if(board[i][j]=='O')
                    board[i][j] = 'X';
                // Now, convert the '.' into 'O' as they were connected to some border 'O'.
				else if(board[i][j]=='.')
                    board[i][j] = 'O';
    }
};