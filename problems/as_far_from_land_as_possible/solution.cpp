class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q,q1;
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i-1,j});
                    q.push({i+1,j});
                    q.push({i,j-1});
                    q.push({i,j+1});
                }
            }
        }
        int steps = 0;
        while(!q.empty()) {
            steps++;
            while(!q.empty()) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                if(i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == 0) {
                    grid[i][j] = steps;
                    q1.push({ i - 1, j }), q1.push({ i + 1, j }), q1.push({ i, j - 1 }), q1.push({ i, j + 1 });
                }
            }
            swap(q1,q);
        }
          return steps == 1 ? -1 : steps - 1;
    }
};