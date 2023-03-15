class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();

        for (int i = n - 2; i >= 0; i--) {
            // Total cost of painting the nth house red.
            costs[i][0] += min(costs[i + 1][1], costs[i + 1][2]);
            // Total cost of painting the nth house green.
            costs[i][1] += min(costs[i + 1][0], costs[i + 1][2]);
            // Total cost of painting the nth house blue.
            costs[i][2] += min(costs[i + 1][0], costs[i + 1][1]);
        }
        
        return min(min(costs[0][0], costs[0][1]), costs[0][2]);        
    }
};
