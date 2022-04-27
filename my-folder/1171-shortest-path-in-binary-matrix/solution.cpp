class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 1;
        if(n == 0) return -1;
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        grid[0][0] = 1;
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        while(!q.empty()) {
            auto head = q.front();
            q.pop();
            if(head.first == n -1 && head.second == n -1) return grid[n-1][n-1];
            for(int i = 0; i < 8; i++) {
                int x = head.first + directions[i][0];
                int y = head.second + directions[i][1];
                
                if(x >= 0 && x < n && y >=0 && y < n && grid[x][y] == 0) {
                    q.push(make_pair(x,y));
                    grid[x][y] = grid[head.first][head.second] + 1;
                }
            }
        }
        return -1;
    }
};
