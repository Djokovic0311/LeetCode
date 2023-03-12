class Solution {
public:
    int visited[100][100][101] = {};
    bool dfs(vector<vector<char>>& grid, int i, int j, int curr) {
        int m = grid.size(), n = grid[0].size();
        
        curr += grid[i][j] == '(' ? 1 : -1;
        if(curr < 0 || curr > (m+n)/2 || visited[i][j][curr]) return false;
        visited[i][j][curr] = true;
        if(i == m-1 && j == n-1 && curr== 0) return true;
        if(i < m-1 && dfs(grid, i+1, j, curr))return true;
        if(j < n-1 && dfs(grid, i, j+1, curr)) return true;
        return false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {

        if(grid[0][0] != '(') return false;
        return dfs(grid, 0, 0, 0);
    }
};
