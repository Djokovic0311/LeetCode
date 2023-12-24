class Solution {
public:
    int bfs(vector<vector<int>>& grid, int row, int col, int totalHouses) {
        // record the sum of path
        int visitedHouses = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        queue<pair<int,int>> q;
        int distanceSum = 0;
        int steps = 0;

        vector<vector<bool>> visited(rows,vector(cols,false));
        visited[row][col] = true;
        q.push({row, col});
        while(!q.empty() && visitedHouses != totalHouses) {
            for(int i = q.size(); i > 0; --i) {
                auto tmp = q.front();
                int row = tmp.first, col = tmp.second;
                q.pop();
                if(grid[row][col] == 1) {
                    distanceSum += steps;
                    visitedHouses++;
                    continue;
                } 
                for(int i = 0; i < 4; i++) {
                    int nr = row + dx[i];
                    int nc = col + dy[i];
                    if(nr >= 0 && nr < rows && nc >= 0 && nc <cols) {
                        if(grid[nr][nc] != 2 && !visited[nr][nc]) {
                            visited[nr][nc] = true;
                            q.push({nr,nc});
                        } 
                    }
                }

            }
            steps++;
        }
        if(visitedHouses != totalHouses) {
            for(int row = 0; row < rows; row++) {
                for(int col = 0; col < cols; col++) {
                    if(grid[row][col] == 0 && visited[row][col]) {
                        grid[row][col] = 2;
                    }
                }
            }
            return INT_MAX;
        }

        return distanceSum;

    }
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int totalHouses = 0;
        int res = INT_MAX;
        for(int i = 0; i < m;i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    totalHouses++;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j] == 0){
                    res = min(res, bfs(grid,i,j,totalHouses));
                    // cout << i << " " << j << " " << bfs(grid,i,j,totalHouses) << endl;;
                }
                    
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
