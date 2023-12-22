class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        grid[0][0] = 1;
        q.push(make_pair(0,0));
        vector<vector<int>> dirs = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

        while(!q.empty()) {
            auto head = q.front();
            q.pop();
            if(head.first == n-1 && head.second == n-1) return grid[n-1][n-1];
            for(auto dir : dirs) {
                int x = head.first + dir[0], y = head.second + dir[1];
                
                if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0) {
                    q.push(make_pair(x,y));
                    grid[x][y] = grid[head.first][head.second]+1;
                }
            }
        }


        return -1;
    }
};
