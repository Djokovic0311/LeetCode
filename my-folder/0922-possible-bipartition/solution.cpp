class Solution {
public:
    bool bfs(int source, vector<vector<int>>& adjList, vector<int>& color) {
        queue<int> q;
        q.push(source);
        color[source] = 0;
        while(!q.empty()) {
            int tmp = q.front();
            q.pop();
            for(int neighbor : adjList[tmp]) {
                if(color[neighbor] == color[tmp]) return false;
                if(color[neighbor] == -1) {
                    color[neighbor] = 1 - color[tmp];
                    q.push(neighbor);
                }
            }
        }
        return true;
        
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjList(n+1);
        for(auto d : dislikes) {
            adjList[d[0]].push_back(d[1]);
            adjList[d[1]].push_back(d[0]);
        }

        vector<int> color(n+1, -1);
        for(int i = 1; i <= n; i++) {
            if(color[i] == -1 && !bfs(i, adjList, color)) return false;
        }

        return true;
    }
};
