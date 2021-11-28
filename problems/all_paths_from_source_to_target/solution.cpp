class Solution {
public:
    int target;
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<vector<int>>& graph, int currNode = 0) {
        tmp.push_back(currNode);
        if(currNode == target) res.push_back(tmp);
        else for(int node : graph[currNode]) {
            dfs(graph, node);
        }
        tmp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size() - 1;
        dfs(graph, 0);
        return res;
    }
};