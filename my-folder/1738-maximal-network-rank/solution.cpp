class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
         // Create a map to store the number of roads connected to each city
        unordered_map<int, int> cityToRoadCount;
        
        // Create a map to store the direct connections between cities
        unordered_map<int, unordered_map<int, bool>> directConnection;
        
        // Populate the maps based on the input roads array
        for (const vector<int>& road : roads) {
            int a = road[0];
            int b = road[1];
            
            // Increase the road count for both cities involved in this road
            cityToRoadCount[a]++;
            cityToRoadCount[b]++;
            
            // Mark that there is a direct connection between these two cities
            directConnection[a][b] = true;
            directConnection[b][a] = true;
        }
        
        // Compute the maximal network rank
        int maximalNetworkRank = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Calculate the network rank for this pair of cities
                int rank = cityToRoadCount[i] + cityToRoadCount[j];
                
                // Check if there is a direct connection between these two cities
                if (directConnection[i][j]) {
                    // If so, we should subtract 1 from the rank
                    rank -= 1;
                }
                
                // Update the maximal network rank if necessary
                maximalNetworkRank = max(maximalNetworkRank, rank);
            }
        }
        
        return maximalNetworkRank;       
    }
};
