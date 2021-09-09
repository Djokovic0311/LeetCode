class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        if(m == 0 || n == 0) return 0;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j]){
                    ans += 4;
                    if(i > 0 && grid[i-1][j]) ans -= 2;
                    if(j > 0 && grid[i][j-1]) ans -= 2;
                }     
        return ans;
    }
};
