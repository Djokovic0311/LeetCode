
class Solution {
public:
    // Helper function to run DFS on the graph and compute the reversal counts
    int dfs(vector<pair<int, int>> graph[], pair<int, int> distanceReversalCount[], bool visited[], int currentNode) {
        visited[currentNode] = true;
        int totalReversalsInSubtree = 0;

        // Iterate through neighbors of current node
        for (auto &neighbor : graph[currentNode]) {
            int nextNode = neighbor.first;

            if (!visited[nextNode]) {
                // Distance of the next node will be one more than the distance of current node
                distanceReversalCount[nextNode].first = distanceReversalCount[currentNode].first + 1;
                
                // Initialize reversal count for next node the same as current node's count
                distanceReversalCount[nextNode].second = distanceReversalCount[currentNode].second;

                // If current edge needs a reversal, increment the count
                if (neighbor.second) {
                    distanceReversalCount[nextNode].second++;
                    totalReversalsInSubtree++;
                }

                // Recursively compute for child nodes
                totalReversalsInSubtree += dfs(graph, distanceReversalCount, visited, nextNode);
            }
        }

        // Return total reversal count in subtree rooted at the current node
        return totalReversalsInSubtree;
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> graph[n];
        pair<int, int> distanceReversalCount[n];  // distance, reversal count
        bool visited[n];

        // Construct the graph with edge direction information
        for (auto &edge : edges) {
            int from = edge[0];
            int to = edge[1];

            // Original directed edge (no reversal needed)
            graph[from].emplace_back(to, 0);

            // Reverse edge (indicates reversal needed)
            graph[to].emplace_back(from, 1);
        }

        // Initialize variables
        fill_n(visited, n, false);
        for (int i = 0; i < n; i++) {
            distanceReversalCount[i] = {0, 0};
        }

        int totalReversals = dfs(graph, distanceReversalCount, visited, 0); // Start DFS from root node (node 0)

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int reversalsForNode = (totalReversals - distanceReversalCount[i].second) +
                                   (distanceReversalCount[i].first - distanceReversalCount[i].second);
            ans.push_back(reversalsForNode);
        }

        return ans;
    }
};
