class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        // Adjacency list representation of the graph
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& highway : highways) {
            int u = highway[0], v = highway[1], w = highway[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        // Priority queue for Dijkstra's algorithm
        // Each element is a tuple - {total cost, current city, discounts used}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        // Start from city 0 with 0 cost and 0 discounts used
        pq.emplace(0, 0, 0);

        // To keep track of minimum cost to reach a city with certain discounts used
        vector<vector<int>> visited(n, vector<int>(discounts + 1, INT_MAX));

        while (!pq.empty()) {
            int cost, city, used;
            tie(cost, city, used) = pq.top(); pq.pop();

            if (city == n - 1) return cost;  // Reached the destination

            if (visited[city][used] <= cost) continue;  // If this state is already processed, skip

            visited[city][used] = cost;

            for (const auto& [nextCity, toll] : graph[city]) {
                // If no discount is used yet on the current highway
                if (used < discounts) {
                    // Using the discount
                    pq.emplace(cost + toll / 2, nextCity, used + 1);
                }

                // Without using the discount
                pq.emplace(cost + toll, nextCity, used);
            }
        }

        return -1;  // If city n-1 is not reachable
    }
};

