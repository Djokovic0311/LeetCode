class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m,'.'));

        for(int i = m-1; i >= 0; i--) {
            int cnt = 0;
            int y = m - i -1;
            for(int j = 0; j < n; j++) {
                if(box[i][j] == '#') {
                    cnt++;
                }
                else if(box[i][j]=='*'){
                    //Obstacle
                    res[j][y]='*';
                    for(int c=1; c<=cnt; ++c) 
                        res[j-c][y]='#';
                    cnt=0;
                }
            }
            for(int c=1; c<=cnt; ++c) res[n-c][y]='#';
        }
        return res;
    }
};
