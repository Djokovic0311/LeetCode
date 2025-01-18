class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int r = grid.size(), c = grid[0].size();
        deque<pair<int,int>> dq;
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        dq.push_back(make_pair(0,0));
        dist[0][0] = 0;
        while(!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            for(int i = 0; i < 4; i++) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx >= 0 && nx < r && ny >= 0 && ny < c) {
                    int cost = dist[x][y] + (grid[x][y] == i+1 ? 0 : 1);
                    if(dist[nx][ny] > cost) {
                        dist[nx][ny] = cost;
                        if(cost == dist[x][y]) {
                            dq.push_front(make_pair(nx, ny));
                        } else {
                            dq.push_back(make_pair(nx, ny));
                        }
                    }   
                }
            }
        }

        return dist[r-1][c-1];
    }
};
