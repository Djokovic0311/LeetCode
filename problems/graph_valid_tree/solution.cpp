class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> visited(n, 0);

        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        queue<int> q;
        q.push(0);
        visited[0] = 1;
        while(!q.empty()) {
            int tmp = q.front();
            q.pop();
            // visited[tmp] = 1;

            for(int i = 0; i < graph[tmp].size(); i++) {
                if(visited[graph[tmp][i]] == 1)
                    return false;
                if(visited[graph[tmp][i]] == 0) {
                visited[graph[tmp][i]] = 1;
                q.push(graph[tmp][i]);                    
                }

            }
            visited[tmp] = 2;
        }
		for(auto x:visited){
			if(x==0) return false;
		}
		return true;
    }
};