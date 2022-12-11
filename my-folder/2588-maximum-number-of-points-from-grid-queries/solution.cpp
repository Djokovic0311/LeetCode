using ll = long long;

class Solution {
 public:
  std::vector<int> maxPoints(std::vector<std::vector<int>>& grid,
                             std::vector<int>& queries) {
    auto const m = std::size(grid);
    auto const n = std::size(grid[0]);
    auto const max_q =
        *std::max_element(std::begin(queries), std::end(queries));
    std::vector<ll> res(max_q + 1);
    auto cmp = [&](auto a, auto b) {
      return grid[a.first][a.second] > grid[b.first][b.second];
    };
    using pii = std::pair<ll, ll>;
    std::priority_queue<pii, std::vector<pii>, decltype(cmp)> pq(cmp);
    std::vector visited(m, std::vector(n, false));
    pq.push({0, 0});
    visited[0][0] = true;
    for (ll i = 1; i <= max_q; ++i) {
      res[i] += res[i - 1];
      while (not std::empty(pq)) {
        auto const [x, y] = pq.top();
        if (grid[x][y] >= i) break;
        pq.pop();
        ++res[i];
        constexpr static ll dx[] = {0, 0, -1, 1};
        constexpr static ll dy[] = {-1, 1, 0, 0};
        for (ll k = 0; k < 4; ++k) {
          auto const new_x = x + dx[k];
          auto const new_y = y + dy[k];
          if (new_x >= 0 and new_y >= 0 and new_x < m and new_y < n) {
            if (not visited[new_x][new_y]) {
              visited[new_x][new_y] = true;
              pq.push({new_x, new_y});
            }
          }
        }
      }
    }
    std::vector<int> ans;
    for (auto q : queries) ans.push_back(res[q]);
    return ans;
  }
};
