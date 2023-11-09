class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layers = min(m,n) / 2;
        for(int layer = 0; layer < layers; ++layer){
            int hlength = n - 2 * layer, vlength = m - 2 * layer;
            int shift = k % (2 * hlength + 2 * (vlength - 2));
            while(shift--){
                int x = layer, y = layer;
                int prev = grid[x][y];
                for(int i = 1; i < vlength; i++) swap(grid[++x][y], prev);
                for(int i = 1; i < hlength; i++) swap(grid[x][++y], prev);
                for(int i = 1; i < vlength; i++) swap(grid[--x][y], prev);
                for(int i = 1; i < hlength; i++) swap(grid[x][--y], prev);
            }         
        }
        return grid;
    }
};
