class Solution {
public:
    vector<int> res, count;
    vector<set<int>> graph;
    int N;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        res.resize(n);
        count.resize(n,1);
        N = n;
        for(auto e : edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        dfs(0,-1);
        dfs2(0,-1);
        return res;
    }
    void dfs(int node, int parent) {
        for(int child : graph[node]) {
            if(child != parent) {
                dfs(child, node);
                count[node] += count[child];
                res[node] += res[child] + count[child];
            }
        }
    }
    void dfs2(int node, int parent) {
        for(int child : graph[node]) {
            if(child != parent) {
                res[child] = res[node] - count[child] + N - count[child];
                dfs2(child, node);
            }
        }
    }
};
