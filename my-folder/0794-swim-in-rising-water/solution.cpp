class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        unordered_set<int> seen;
        auto cmp = [&](int a, int b) {
            return grid[a / N][a % N] > grid[b / N][b % N];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        pq.push(0);
        seen.insert(0);
        int ans = 0;

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        while (!pq.empty()) {
            int k = pq.top(); pq.pop();
            int r = k / N, c = k % N;
            ans = max(ans, grid[r][c]);
            if (r == N - 1 && c == N - 1)
                return ans;

            for (int i = 0; i < 4; ++i) {
                int cr = r + dr[i], cc = c + dc[i];
                int ck = cr * N + cc;
                if (cr >= 0 && cr < N && cc >= 0 && cc < N && !seen.count(ck)) {
                    seen.insert(ck);
                    pq.push(ck);
                }
            }
        }

        return -1; // should never reach here
    }
};

