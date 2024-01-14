class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> destinations;
        
        for (const vector<int>& edge : edges) {
            destinations.insert(edge[1]);
        }
        
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            if (destinations.find(i) == destinations.end()) {
                result.push_back(i);
            }
        }
        
        return result;        
    }
};
