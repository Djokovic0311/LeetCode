class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        queue<pair<int, int>> q; // Pair of current value and number of operations
        unordered_set<int> visited; // To avoid revisiting the same number

        q.push({x, 0});
        visited.insert(x);

        while (!q.empty()) {
            int current = q.front().first;
            int operations = q.front().second;
            q.pop();

            if (current == y) {
                return operations;
            }

            // Try all 4 operations
            if (current % 11 == 0 && visited.find(current / 11) == visited.end()) {
                q.push({current / 11, operations + 1});
                visited.insert(current / 11);
            }
            if (current % 5 == 0 && visited.find(current / 5) == visited.end()) {
                q.push({current / 5, operations + 1});
                visited.insert(current / 5);
            }
            if (current > 1 && visited.find(current - 1) == visited.end()) { // Check to avoid going below 1
                q.push({current - 1, operations + 1});
                visited.insert(current - 1);
            }
            if (visited.find(current + 1) == visited.end()) {
                q.push({current + 1, operations + 1});
                visited.insert(current + 1);
            }
        }

        return -1; // If y is not reachable
    }
};
