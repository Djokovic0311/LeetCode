class Solution {
public:
    bool isValid(const int& x, const int& y, const vector<vector<int>>& maze){
        return x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() && maze[x][y] == 0;
    }

    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,-1,0,1};
        char dirs[4] = {'d', 'l', 'u', 'r'};
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        //dist - instructions - x - y
        priority_queue<tuple<int,string,int,int>, vector<tuple<int,string,int,int>>, greater<tuple<int,string,int,int>>> pq;
        pq.push({0,"",ball[0],ball[1]});
        dist[ball[0]][ball[1]] = 0;

        while(!pq.empty()) {
            auto item = pq.top();
            pq.pop();
            int distance = get<0>(item), x = get<2>(item), y = get<3>(item);
            string instruction = get<1>(item);
            if(x == hole[0] && y == hole[1]) {
                return instruction;
            }
            for(int i = 0; i < 4; i++) {
                int steps = 0;
                int nx = x, ny = y;
                while(isValid(nx+dx[i], ny+dy[i], maze)) {
                    nx += dx[i];
                    ny += dy[i];
                    steps++;
                    if(nx == hole[0] && ny == hole[1])
                        break;                    
                }
                if((nx != x || ny != y ) && dist[nx][ny] >= steps + dist[x][y]) {
                    dist[nx][ny] = steps + dist[x][y];
                    pq.push({dist[nx][ny], instruction +  dirs[i], nx, ny});
                }
                
            }
            
        }

        return "impossible";
    }
};
