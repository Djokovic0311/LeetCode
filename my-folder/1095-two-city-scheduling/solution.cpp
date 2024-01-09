class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;
        int total = 0;
        sort(costs.begin(), costs.end(), [&](vector<int> a, vector<int> b) {
            return a[0] - a[1] < b[0] - b[1];
        });

        for(int i= 0; i < n; i++) {
            total += costs[i][0] + costs[i+n][1];
        }

        return total;
    }
};
