class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int max_fish = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] > 0) {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                int fish_count = 0;

                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();

                    fish_count += grid[r][c];

                    for (auto& dir : directions) {
                        int nr = r + dir.first;
                        int nc = c + dir.second;

                        if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0 && !visited[nr][nc]) {
                            q.push({nr, nc});
                            visited[nr][nc] = true;
                        }
                    }
                }

                max_fish = max(max_fish, fish_count);

                // Reset visited
                for (int r = 0; r < m; ++r) {
                    fill(visited[r].begin(), visited[r].end(), false);
                }
            }
        }
    }

    return max_fish;        
    }
};
