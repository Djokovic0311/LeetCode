class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<int,int>> q;
        int m = maze.size(), n = maze[0].size();
        q.push(make_pair(start[0], start[1]));
        maze[start[0]][start[1]] = -1;
        while(!q.empty()) {
            auto tmp = q.front();
            q.pop();

            for(auto d : directions) {
                int r = tmp.first, c = tmp.second;

                while(r  + d[0]< m && r + d[0] >= 0 && c  + d[1]< n && c+d[1] >= 0 && maze[r+d[0]][c+d[1]] <= 0) {
                    r = r + d[0], c = c + d[1];
                }
                if(r == destination[0] && c == destination[1])
                    return true;
                if(maze[r][c] == 0) {
                    q.push(make_pair(r,c));
                    maze[r][c] = -1;
                }
            }
        }
        return false;        
    }
};
