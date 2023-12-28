class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        vector<vector<int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        queue<pair<int,int>> q;
        int m = rooms.size(), n = rooms[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(rooms[i][j] == 0)
                    q.push(make_pair(i,j));
            }
        }
        
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int r = curr.first, c = curr.second;
            for(int i = 0; i < 4; i++) {
                int nr = r + DIRECTIONS[i][0];
                int nc = c + DIRECTIONS[i][1];
                if(nr < 0 || nr >= m || nc < 0 || nc >= n || rooms[nr][nc] == -1 || rooms[nr][nc] != INT_MAX)
                    continue;
                rooms[nr][nc] = rooms[r][c] + 1;
                q.push(make_pair(nr,nc));
            }
        }
    
    }
};
