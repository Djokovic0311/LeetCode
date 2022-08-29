class Solution {
public:
    void explore(vector<vector<char>>& grid, int r, int c, int R, int C){
        if(r < 0 || r >= R || c < 0 || c >= C) return;
        if(grid[r][c] == '0') return;
        if(grid[r][c] == '1'){
            grid[r][c] = 'm';
            explore(grid, r+1, c, R, C);
            explore(grid, r, c+1, R, C);
            explore(grid, r-1, c, R, C);
            explore(grid, r, c-1, R, C);
        }
        return;
    } 

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int R = grid.size();
        int C = grid[0].size();

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j] == 'm') continue;
                if(grid[i][j] == '1'){
                    count++;
                    explore(grid, i,j, R, C);
                }
            }
        }
        return count;
    }
};