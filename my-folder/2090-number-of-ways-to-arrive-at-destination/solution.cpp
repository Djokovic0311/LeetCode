class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++)
        {
            // {u, v, w}
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector<long long> weight(n, 1e15);
        vector<int> way(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        weight[0] = 0;
        way[0] = 1;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            long long dist = it.first;
            int node = it.second;

            if (node == n - 1)
            {
                break;
            }
            for (auto &&neighbour : adj[node])
            {
                int newnode = neighbour.first;
                long long newdist = neighbour.second;

                if (newdist + dist < weight[newnode])
                {
                    weight[newnode] = newdist + dist;
                    way[newnode] = way[node];
                    pq.push({newdist + dist, newnode});
                }
                else if (newdist + dist == weight[newnode])
                {
                    way[newnode] = (way[newnode] + way[node] * 1LL) % MOD;
                }
            }
        }
        return way[n - 1];
    }
};
