class Solution {
public:
    bool bfs(vector<vector<int>>& g,int r,int c,vector<vector<bool>>&vi){
        vector<vector<pair<int,int>>>dirr(7);
        dirr[1] = {{0,-1},{0,1}};
        dirr[2] = {{-1,0},{1,0}};
        dirr[3] = {{0,-1},{1,0}};
        dirr[4] = {{0,1},{1,0}};
        dirr[5] = {{0,-1},{-1,0}};
        dirr[6] = {{0,1},{-1,0}};
        queue<pair<int,int>>q;
        q.push({r,c});
        vi[r][c]=true;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(x==g.size()-1 && y==g[0].size()-1) return true;
                
                int type=g[x][y];
                for (int k = 0; k < 2; k++) {
                    int u = x + dirr[type][k].first, v = y + dirr[type][k].second;
                    if (u >= 0 && u < g.size() && v >= 0 && v < g[0].size() && vi[u][v] == false) {
                        vi[u][v] = true;
                        int z=g[u][v];
                        int x1=u+dirr[z][0].first;
                        int y1=v+dirr[z][0].second;
                        int x2=u+dirr[z][1].first;
                        int y2=v+dirr[z][1].second;
                    
                        if((x==x1 && y==y1) || (x==x2 && y==y2))
                            q.push({u,v});
                    }
                }
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        bool valid = bfs(grid,0,0,vis);
        return valid;
    }
};