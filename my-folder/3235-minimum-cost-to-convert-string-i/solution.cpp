class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        if (source.length() != target.length()) return -1;

        vector<vector<pair<int, int>>> graph(256);
        for (int i = 0; i < original.size(); ++i) {
            graph[original[i]].push_back({changed[i], cost[i]});
        }

        // Memoization table for storing the cost of transforming each character.
        unordered_map<int, unordered_map<int, int>> memo;
        long long totalCost = 0;

        for (int i = 0; i < source.length(); ++i) {
            if (source[i] == target[i]) continue;
            // Use memoization to avoid recalculating costs.
            if (memo[source[i]].count(target[i]) == 0) {
                int transformationCost = dijkstra(graph, source[i], target[i]);
                memo[source[i]][target[i]] = transformationCost;
            }
            if (memo[source[i]][target[i]] == -1) return -1;
            totalCost += memo[source[i]][target[i]];
        }

        return totalCost;
    }

private:
    int dijkstra(const vector<vector<pair<int, int>>>& graph, char start, char end) {
        vector<int> dist(256, numeric_limits<int>::max());
        dist[start] = 0;

        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;
            if (u == end) return dist[u];

            for (auto& [v, weight] : graph[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[end] != numeric_limits<int>::max() ? dist[end] : -1;
    }
};
