class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<int> color(n,0);
        for(int i = 0; i < n; i++) {
            if(color[i]) continue;
            color[i] = 1;
            q.push(i);
            while(!q.empty()) {
                int top = q.front();
                q.pop();
                for(auto neighbor : graph[top]) {
                    if(!color[neighbor]) {
                        color[neighbor] = -color[top];
                        q.push(neighbor);
                    }
                    else if(color[neighbor] == color[top])
                        return false;
                }
            }            
        }
        return true;
    }
};