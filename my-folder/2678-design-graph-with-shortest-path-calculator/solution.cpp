class Graph {
public:
    Graph(int n, vector<vector<int>> edges) {
        this->n = n;
        for (const vector<int>& edge : edges) {
            addEdge(edge);
        }
    }
    
    void addEdge(vector<int> edge) {
        int from = edge[0];
        int to = edge[1];
        int cost = edge[2];
        adjList[from].push_back({to, cost});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(n, numeric_limits<int>::max());
        dist[node1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node1});

        while (!pq.empty()) {
            int curNode = pq.top().second;
            int curCost = pq.top().first;
            pq.pop();

            if (curNode == node2) {
                return curCost;
            }

            if (curCost > dist[curNode]) {
                continue;
            }

            for (const pair<int, int>& neighbor : adjList[curNode]) {
                int nextNode = neighbor.first;
                int edgeCost = neighbor.second;

                if (curCost + edgeCost < dist[nextNode]) {
                    dist[nextNode] = curCost + edgeCost;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        return -1;
    }
    
private:
    int n;
    unordered_map<int, vector<pair<int, int>>> adjList;    
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
