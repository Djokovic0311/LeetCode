class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int i, j, k, u, v, s;
        vector<vector<int>> graph(n, vector<int>());
        queue<int> q;
        vector<int> visited(n, 0);
        for(i = 0; i < dislikes.size(); i++){
            u = dislikes[i][0] - 1;
            v = dislikes[i][1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(i = 0; i < n; i++){
            if(visited[i] != 0){
                continue;
            }
            q.push(i);
            visited[i] = 1;
            while(!q.empty()){
                s = q.size();
                for(j = 0; j < s; j++){
                    u = q.front();
                    q.pop();
                    for(k = 0; k < graph[u].size(); k++){
                        v = graph[u][k];
                        if(visited[v] == 0){
                            q.push(v);
                            visited[v] = visited[u] == 1 ? 2 : 1;
                        }
                        
                        if(visited[v] == visited[u]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};