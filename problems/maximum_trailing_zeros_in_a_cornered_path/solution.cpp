class Solution {
public:
    int mod_2(int num) {
        int count = 0;
        while(num % 2 == 0) {
            count++;
            num /= 2;
        }
        return count;
    }
    int mod_5(int num) {
        int count = 0;
        while(num % 5 == 0) {
            count++;
            num /= 5;
            
        }
        return count;
    }
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<pair<int, int>>> mat(n, vector<pair<int, int>> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int val = grid[i][j];
                pair<int, int> p;
                while (val % 2 == 0) {
                    ++p.first;
                    val /= 2;
                }
                val = grid[i][j];
                while (val % 5 == 0) {
                    ++p.second;
                    val /= 5;
                }
                mat[i][j] = p;
            }
        }
        vector<vector<pair<int, int>>> preRow(n, vector<pair<int, int>> (m));
        for (int i = 0; i < n; i++) {
            preRow[i][0] = mat[i][0];
            for (int j = 1; j < m; j++) {
                preRow[i][j].first = preRow[i][j - 1].first + mat[i][j].first;
                preRow[i][j].second = preRow[i][j - 1].second + mat[i][j].second;
            }
        }
        vector<vector<pair<int, int>>> preCol(n, vector<pair<int, int>> (m));
        for (int i = 0; i < m; i++) {
            preCol[0][i] = mat[0][i];
            for (int j = 1; j < n; j++) {
                preCol[j][i].first = preCol[j - 1][i].first + mat[j][i].first;
                preCol[j][i].second = preCol[j - 1][i].second + mat[j][i].second;
            }
        }
        auto rowSum = [&] (int r, int l, int c) -> pair<int, int> {
            if (c < 0 || c >= m) return {0, 0};
            if (l < 0 || l >= m ) return {0, 0};
            pair<int, int> p;
            p.first = preRow[r][c].first - (l == 0 ? 0 : preRow[r][l - 1].first);
            p.second = preRow[r][c].second - (l == 0 ? 0 : preRow[r][l - 1].second);
            return p;
        };
        auto colSum = [&] (int c, int l, int r) -> pair<int, int> {
            if (r < 0 || r >= n) return {0, 0};
            if (l < 0 || l >= n ) return {0, 0};
            pair<int, int> p;
            p.first = preCol[r][c].first - (l == 0 ? 0 : preCol[l - 1][c].first);
            p.second = preCol[r][c].second - (l == 0 ? 0 : preCol[l - 1][c].second);
            return p;
        };
        int sol = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pair<int, int> p = rowSum(i, 0, j);
                pair<int, int> q = colSum(j, 0, i - 1);
                pair<int, int> r = rowSum(i, j, m - 1);
                pair<int, int> s = colSum(j, i + 1, n - 1);
                
                sol = max(sol, min(p.first, p.second));
                sol = max(sol, min(q.first, q.second));
                sol = max(sol, min(r.first, r.second));
                sol = max(sol, min(s.first, s.second));
                sol = max(sol, min(p.first + q.first, p.second + q.second));
                sol = max(sol, min(r.first + q.first, q.second + r.second));
                sol = max(sol, min(p.first + s.first, p.second + s.second));
                sol = max(sol, min(r.first + s.first, r.second + s.second));
            }
        }
        return sol;
    }
};