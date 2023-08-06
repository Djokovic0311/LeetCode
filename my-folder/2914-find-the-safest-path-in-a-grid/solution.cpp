
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n;

    bool inGrid(int x, int y) { return 0 <= x && x < n && 0 <= y && y < n; }

    void calculateSafeness(vector<vector<int>>& grid, vector<vector<int>>& safeness) {
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) { // thief
                    q.push({i, j});
                    safeness[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (inGrid(nx, ny) && safeness[nx][ny] > safeness[x][y] + 1) {
                    safeness[nx][ny] = safeness[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    int bfs(vector<vector<int>>& safeness, vector<vector<bool>>& visited) {
        priority_queue<pair<int, pair<int, int>>> q;
        q.push({safeness[0][0], {0, 0}});
        while (!q.empty()) {
            int safe = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            if (x == n - 1 && y == n - 1) return safe;
            if (visited[x][y]) continue;
            visited[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (inGrid(nx, ny)) {
                    q.push({min(safe, safeness[nx][ny]), {nx, ny}});
                }
            }
        }
        return -1;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> safeness(n, vector<int>(n, 1e9));
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        calculateSafeness(grid, safeness);
        return bfs(safeness, visited);
    }
};
