class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int res = 0;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        int a = artifacts.size();
        int d = dig.size(); 
        for(int i = 0; i < d; i++) {
            vis[dig[i][0]][dig[i][1]] = true;
        }
        for(int j = 0; j < a; j++) {
            bool tag = true;
            for(int r = artifacts[j][0]; r <= artifacts[j][2]; r++) {
                for(int c = artifacts[j][1]; c <= artifacts[j][3]; c++) {
                    if(vis[r][c] == false) {tag = false; break;}
                }
                
            }
            res += tag;
        }
        return res;
    }
};