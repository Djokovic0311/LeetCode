class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> incomingEdgesCount(n, 0);

        // Count incoming edges for each node
        for (const auto& edge : edges) {
            int destination = edge[1];
            incomingEdgesCount[destination]++;
        }

        // Find the node with zero incoming edges
        int champion = -1;
        for (int i = 0; i < n; ++i) {
            if (incomingEdgesCount[i] == 0) {
                if (champion == -1) {
                    champion = i;
                } else {
                
                    return -1;
                }
            }
        }

        return champion;        
    }
};
