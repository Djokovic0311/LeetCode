class Solution {
public:
    set<int> seen;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> graph(1001, vector<int>());
        for(auto e : edges) {
            seen.clear();
            if(graph[e[0]].size() && graph[e[1]].size() && dfs(graph, e[0], e[1])) {
                return e;
            }
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        return {};
    }
    bool dfs(vector<vector<int>>& graph, int source, int target) {
        if(!seen.count(source)) {
            seen.insert(source);
            if(source == target) return true;
            for(auto neighbor : graph[source]) {
                if(dfs(graph, neighbor, target)) return true;
            }
        }

        return false;
    }
};
