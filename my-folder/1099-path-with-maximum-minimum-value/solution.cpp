class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    priority_queue<pair<int, pair<int, int>>> pq; // Pair with score and coordinates

    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    pq.push({grid[0][0], {0, 0}});

    while (!pq.empty()) {
        int score = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (x == m - 1 && y == n - 1) return score; // Reached the destination

        for (auto& dir : dirs) {
            int newX = x + dir[0];
            int newY = y + dir[1];

            if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY]) {
                visited[newX][newY] = true;
                int newScore = min(score, grid[newX][newY]);
                pq.push({newScore, {newX, newY}});
            }
        }
    }
    return -1;
    }
};
