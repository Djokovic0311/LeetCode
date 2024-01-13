class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m,'.'));
        // traverse the box by row from the last row
        for(int i = m-1; i >= 0; i--) {
            // cnt of # until now
            int cnt = 0;
            // the column in result
            int y = m - i -1;
            // traverse the box by col from the first column
            for(int j = 0; j < n; j++) {
                if(box[i][j] == '#') {
                    cnt++;
                }
                // meet obstacle
                else if(box[i][j]=='*'){
                    res[j][y]='*';
                    // mark the cells in the same column in upper rows in result
                    for(int c=1; c<=cnt; ++c) 
                        res[j-c][y]='#';
                    cnt=0;
                }
            }
            // meet the bottom
            for(int c=1; c<=cnt; ++c) 
                res[n-c][y]='#';
        }
        return res;
    }
};
