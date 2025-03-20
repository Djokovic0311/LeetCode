class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
        // Create the adjacency list of the graph
        vector<vector<pair<int, int>>> adjList(n);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<bool> visited(n, false);

        // Array to store the component ID of each node
        vector<int> components(n);
        vector<int> componentCost;

        int componentId = 0;

        // Perform BFS for each unvisited node to identify components and
        // calculate their costs
        for (int node = 0; node < n; node++) {
            // If the node hasn't been visited, it's a new component
            if (!visited[node]) {
                // Get the component cost and mark all nodes in the component
                componentCost.push_back(getComponentCost(
                    node, adjList, visited, components, componentId));
                // Increment the component ID for the next component
                componentId++;
            }
        }

        vector<int> answer;

        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];

            if (components[start] == components[end]) {
                // If they are in the same component, return the precomputed
                // cost for the component
                answer.push_back(componentCost[components[start]]);
            } else {
                // If they are in different components, return -1
                answer.push_back(-1);
            }
        }

        return answer;
    }

private:
    // Helper function to calculate the cost of a component using BFS
    int getComponentCost(int source, vector<vector<pair<int, int>>>& adjList,
                         vector<bool>& visited, vector<int>& components,
                         int componentId) {
        queue<int> nodesQueue;

        // Initialize the component cost to the number that has only 1s in its
        // binary representation
        int componentCost = INT_MAX;

        nodesQueue.push(source);
        visited[source] = true;

        // Perform BFS to explore the component and calculate the cost
        while (!nodesQueue.empty()) {
            int node = nodesQueue.front();
            nodesQueue.pop();

            // Mark the node as part of the current component
            components[node] = componentId;

            // Explore all neighbors of the current node
            for (auto& [neighbor, weight] : adjList[node]) {
                // Update the component cost by performing a bitwise AND of the
                // edge weights
                componentCost &= weight;

                // If the neighbor hasn't been visited, mark it as visited and
                // add it to the queue
                if (visited[neighbor]) continue;
                visited[neighbor] = true;
                nodesQueue.push(neighbor);
            }
        }

        return componentCost;
    }
};
