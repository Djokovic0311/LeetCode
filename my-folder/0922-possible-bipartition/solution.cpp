class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(n,vector<int>());
        queue<int> q;
        for(auto d : dislikes) {
            int u = d[0]-1;
            int v = d[1]-1;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> visited(n, 0);
        int i, j, u, v, k,s;
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
                    for(k = 0; k < g[u].size(); k++){
                        v = g[u][k];
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
