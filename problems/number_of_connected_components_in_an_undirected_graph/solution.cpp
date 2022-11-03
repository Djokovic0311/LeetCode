class Solution {
private:
    vector<vector<int>> adjList;
    vector<int> visited;
private:
    void buildGraph(int n, vector<vector<int>>& edges) {
        // vertices info: given (0 ... n-1)
        // edges info: given (pairs of edges)
        // Build adjcency list
        adjList.assign(n, vector<int>(0));
        for (auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        // initialize visted list to keep track of all vertices
        visited.assign(n, -1);
    }
    
    void bfs(int vertex) {
        // initialize queue with vertex & mark it as visited
        queue<int> q;
        q.push(vertex);
        visited[vertex] = 1;
        
        // explore the graph until queue is empty
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (auto neighbor : adjList[node]) {
                if (visited[neighbor] == -1) {
                    // new node: mark it as visited & add it to the queue
                    visited[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
    }
    
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // Step #1 build the graph
        buildGraph(n, edges);
        // Step #2 explore the graph using bfs (or) dfs
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                components++;
                bfs(i);
            }
        }
        return components;
    }
};