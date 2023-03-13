class Solution {
public:
    bool isvalid(vector<vector<char>>& grid, int i, int j,vector<vector<bool>>& visited) {
        int m = grid.size(), n = grid[0].size();
        if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j]!='X' && !visited[i][j])
            return true;
        else return false;
    }
    int getFood(vector<vector<char>>& grid) {
        int res = INT_MAX;
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, pair<int,int>>> q;
        vector<vector<bool> > visited(m, vector<bool>(n,false));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == '*')
                    q.push(make_pair(0,make_pair(i,j))), visited[i][j]=true;
        vector<vector<int>> dirs = {{0,1}, {0,-1},{1,0},{-1,0}};

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto item = q.front();
                q.pop();
                int dis = item.first;
                int i = item.second.first, j = item.second.second;
                
                if (grid[i][j] == '#') {
                    // cout << "food " << i << " " << j << endl;
                    return dis;
                }
                
                for(auto dir : dirs) {
                    int newi = i + dir[0], newj = j + dir[1];
                    if(isvalid(grid, newi, newj, visited)) {
                        cout << newi << " " << newj << endl;
                        q.push(make_pair(dis+1,make_pair(newi,newj)));
                        // grid[newi][newj] = '$';
                        visited[newi][newj] = true;                        
                    }
                }
            }
            // cout << endl;

        }
        return -1;
    }
};
