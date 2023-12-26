class Solution {
public:
    unordered_map<int, unordered_set<int>> adjList;
    int treeDiameter(vector<vector<int>>& edges) {
        if(edges.size() == 0) return 0;
        for(auto edge : edges) {
            adjList[edge[0]].insert(edge[1]);
            adjList[edge[1]].insert(edge[0]);
        }
        vector<int> run1 = bfs(edges[0][0]);
        vector<int> run2 = bfs(run1[0]);
        return run2[1];
    }

    vector<int> bfs(int node) {
        unordered_set<int> seen;
        queue<int> q;
        q.push(node);
        seen.insert(node);
        int level = 0;
        int furtherest_node = node;

        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int tmp = q.front();
                q.pop();
                for(int neighbor : adjList[tmp]) {
                    if(seen.count(neighbor)) continue;
                    seen.insert(neighbor);
                    q.push(neighbor);
                    furtherest_node = neighbor;
                }
            }
            level++;
        }

        return {furtherest_node, level-1};
    }
};
