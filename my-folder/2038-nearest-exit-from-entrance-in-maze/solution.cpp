class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(maze[i][j] == '.' && (i == 0 || j == 0 || i == m-1 || j == n-1) && (i != entrance[0] || j != entrance[1])) {
                    maze[i][j] = 'E';
                }
            }
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        int steps = 0;
        while(!q.empty()) {
            int sz = q.size();
            steps++;

            for(int i = 0; i < sz; i++) {
                auto tmp = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int nx = tmp.first + dx[i], ny = tmp.second + dy[i];

                    if(nx >= 0 && nx <m && ny >= 0 && ny <n) {
                        if(maze[nx][ny] == 'E') return steps;
                        else if(maze[nx][ny] != '+') {
                            maze[nx][ny] = '+';
                            q.push({nx, ny});
                        }
                    }
                }
            }
            
        }
        return -1;
    }
};
