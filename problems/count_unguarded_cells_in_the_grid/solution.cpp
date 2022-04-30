class Solution {
public:
    bool isvalid(int m, int n, int i, int j) {
        if(i >= 0 && i < m && j >= 0 && j < n)
            return true;
        return false;
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> v(m,vector(n,0));
        int res = 0;
        for(auto g : guards) {
            v[g[0]][g[1]] = 1;
        }
        for(auto w : walls) {
            v[w[0]][w[1]] = 2;
        }
        for(auto g : guards) {
            int x = g[0], y = g[1];
            for(int tx = x+1,ty = y; tx < m && v[tx][ty] != 1 && v[tx][ty] != 2; tx++) {
                if(v[tx][ty] == 0)
                    v[tx][ty] = -1;
            }
            for(int tx = x-1,ty = y; tx >= 0 && v[tx][ty] != 1 && v[tx][ty] != 2; tx--) {
                if(v[tx][ty] == 0)
                    v[tx][ty] = -1;
            }
            for(int tx = x,ty = y-1; ty >= 0 && v[tx][ty] != 1 && v[tx][ty] != 2; ty--) {
                if(v[tx][ty] == 0)
                    v[tx][ty] = -1;
            }
            for(int tx = x,ty = y+1; ty < n && v[tx][ty] != 1 && v[tx][ty] != 2; ty++) {
                if(v[tx][ty] == 0)
                    v[tx][ty] = -1;
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // cout <<v[i][j] << ' ';
                if(v[i][j] == 0)
                    res++;
            }
            // cout << endl;
        }
        return res;
    }
};