class Solution {
public:
    vector<vector<int>> grid;
    int N;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    int largestIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        int n = grid.size();
        N = n;
        int res = 0;
        int idx = 2;
        vector<int> area(N*N+2,0);

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(this->grid[i][j] == 1)
                    area[idx] = dfs(i,j,idx);
                    idx++;
            }
        }
        for(int x : area)
            res = max(res, x);

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(this->grid[i][j] == 0) {
                   
                    set<int> seen;
                    for(int move : neighbors(i,j)) {
                        if(this->grid[move/N][move%N] > 1) {
                            // this cell has been visited
                            seen.insert(this->grid[move/N][move%N]);
                        }
                    }
                    int toggle = 1; // toggle this 0 to 1
                    for(int i : seen) {
                        toggle += area[i];
                    }
                    res = max(res, toggle);
                }
            }
        }
        return res;
    }

    int dfs(int r, int c, int& index) {
        // calculate the area
        int ans = 1;
        grid[r][c] = index;
        for(int move : neighbors(r,c)) {
            if(grid[move/N][move%N] == 1) {
                grid[move/N][move%N] = index;

                ans += dfs(move/N, move % N, index);
            }
        }

        return ans;
        
    }
    vector<int> neighbors(int r, int c) {
        vector<int> res;
        for(int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(0<= nr && nr < N && nc >= 0 && nc < N) {
                res.push_back(nr * N + nc);
            }
        }

        return res;
    }
};
