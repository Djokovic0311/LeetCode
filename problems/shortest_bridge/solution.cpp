class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    void dfs(int i,int j,int r,int c,vector<vector<int>>& grid)
    {
        grid[i][j] = -1;
        for(int k=0;k<4;k++)
        {
            int x = dx[k]+i;
            int y = dy[k]+j;
            if(x>=0 && x<c && y>=0 && y<r && grid[x][y]== 1)
                dfs(x,y,r,c,grid);       
        }   
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        bool isfirst = true;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j] == 1) {
                    dfs(i,j,r,c,grid);
                    isfirst = false;
                }
                if(!isfirst)
                    break;
            }
            if(!isfirst)
                break;
        }
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j] == 1) {
                    grid[i][j]=2;
                    q.push({i,j});
                }
            }
        }
        int ans = 0;
        while(!q.empty())
        {
            ans++;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                pair<int,int> temp = q.front();
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int x = temp.first + dx[k];
                    int y = temp.second + dy[k];
                    if(x>=0 && x<r && y>=0 && y<c && grid[x][y]!=2)
                    {
                        if(grid[x][y] == -1)
                            return ans-1;
                        grid[x][y] = 2;
                        q.push({x,y});
                    }
                }    
            }   
        }
        return -1;    
    }
};