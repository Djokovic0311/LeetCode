
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        const int MOD = 12345;

        int l = n * m;
        cout << l << endl;
        vector<int> ans(l);
        ans[0] = 1;
        for(int i = 1; i < n*m; i++) {
            // cout << grid[(i-1)/m][(i-1)%m] <<endl;
            ans[i] =  grid[(i-1)/m][(i-1)%m]%MOD * (ans[i-1] %MOD);
            
        }
        int R = 1;
        for(int i = l-1; i >= 0; i--) {
            ans[i] = ans[i]%MOD * (R% MOD);
            R = R%MOD * (grid[i/m][i%m] % MOD);
            // cout << ans[i] << " ";
        }

        // Compute the product matrix
        vector<vector<int>> p(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                p[i][j] = ans[i*m+j]%MOD;
                // cout <<  p[i][j] << " ";
            }
            // cout << endl;
        }

        return p;
    }

};
