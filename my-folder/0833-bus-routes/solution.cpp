class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        // Build graph: map each stop to the buses that go through it
        unordered_map<int, vector<int>> stopToBus;
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                stopToBus[stop].push_back(i);
            }
        }

        // BFS
        queue<int> q;
        unordered_set<int> visitedStops;
        unordered_set<int> visitedBuses;
        q.push(source);
        visitedStops.insert(source);
        int busesTaken = 0;

        while (!q.empty()) {
            ++busesTaken;
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                int currentStop = q.front();
                q.pop();
                for (int bus : stopToBus[currentStop]) {
                    if (visitedBuses.count(bus)) continue;
                    visitedBuses.insert(bus);
                    for (int nextStop : routes[bus]) {
                        if (nextStop == target) return busesTaken;
                        if (visitedStops.count(nextStop)) continue;
                        visitedStops.insert(nextStop);
                        q.push(nextStop);
                    }
                }
            }
        }

        return -1;        
    }
};
