class Solution {
public:
    bool isValid(vector<vector<char>>& maze, vector<vector<bool>>& visited, int i,int j) {
        return i < maze.size() && i>= 0 && j < maze[0].size() && j >=0&& maze[i][j] !='+' && !visited[i][j];
    }
    bool isexit(vector<vector<char>>& maze, int i,int j) {
        return maze[i][j] !='+' && (i == 0 || i == maze.size()-1 || j == 0 || j == maze[0].size()-1);
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int m = maze.size(), n = maze[0].size();
        int dirs[5] = {0, -1, 0, 1, 0};

        auto is_exit = [&](int i, int j) -> int
        {
            return (i!=e[0] || j!=e[1]) && (i*j==0 or i==m-1 or j==n-1);
        };
        
        deque<array<int,3>> dq = {{e[0],e[1],0}};
        
        while (!dq.empty())
        {
            auto [i,j,s] = dq.front(); dq.pop_front();
            
            for (int d = 0; d < 4; ++d)
            {
                int ii = i + dirs[d], jj = j + dirs[d + 1];
                if (ii < 0 or ii >= m or jj < 0 or jj >= n or maze[ii][jj] == '+')
                    continue;
                maze[ii][jj] = '+';
                if (is_exit(ii,jj)) return s+1;
                dq.push_back({ii,jj,s+1});
            }
        }
        
        return -1;
    }
};