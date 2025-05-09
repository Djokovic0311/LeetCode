class Solution {
public:
    struct cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];  
        }
    };
    
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        int maxDistance = INT_MAX;
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        vector<vector<int>> visited(m, vector<int>(n,0));
        vector<vector<int>> distance(m, vector<int>(n, maxDistance));
        int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        distance[0][0] = 0;
        pq.push({0, 0, 0});
        
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int x = node[0], y = node[1];
            if(visited[x][y]) continue;
            visited[x][y] = 1;
            for(int i = 0; i < 4; i++) {
                int nx = x + direction[i][0];
                int ny = y + direction[i][1];
                if(nx<0 || ny < 0 || nx >= m || ny >= n) continue;
                int dist = max(distance[x][y], moveTime[nx][ny]) + 1;
                if(distance[nx][ny] > dist) {
                    distance[nx][ny] = dist;
                    pq.push({nx, ny, dist});
                }
            }
        }
        return distance[m-1][n-1];
    }
};
