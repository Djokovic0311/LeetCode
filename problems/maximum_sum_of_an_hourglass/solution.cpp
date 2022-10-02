class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int mx = INT_MIN;
        int m = grid.size(), n = grid[0].size();
        for(int i = 1; i < m-1; i++) {
            int start = grid[i-1][0] + grid[i-1][1] + grid[i-1][2] + grid[i+1][0] + grid[i+1][1] + grid[i+1][2];
            for(int j = 1; j < n-1; j++) {
                if(j == 1) {
                    start += grid[i][j];
                    // mx = max(start, mx);                    
                }
                else {
                    start -= (grid[i][j-1]+ grid[i-1][j-2]  + grid[i+1][j-2]);
                    start += (grid[i][j]+ grid[i-1][j+1]  + grid[i+1][j+1]);
                    
                }
                // if(start > mx)
                //     cout << i << " " << j <<endl;
                // cout << grid[i][j] << " " << start <<endl;
                mx = max(start, mx);   
            }
        }
        return mx;
    }
};