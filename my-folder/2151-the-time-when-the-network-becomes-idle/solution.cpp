class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<unordered_set<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        // BFS to compute shortest path to master server
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int neighbor : graph[curr]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[curr] + 1;
                    q.push(neighbor);
                }
            }
        }

        int lastMessageTime = 0;
        for (int i = 1; i < n; ++i) {
            int roundTripTime = 2 * dist[i];
            int resend = ((roundTripTime - 1) / patience[i]) * patience[i]; // Calculate next resend time
            lastMessageTime = std::max(lastMessageTime, resend + roundTripTime);
        }

        return lastMessageTime + 1;  
    }
};
