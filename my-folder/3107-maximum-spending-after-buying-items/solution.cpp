class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        int m = values.size();
        int n = values[0].size();

        // Create a max heap for all m * n elements
        priority_queue<int> maxHeap;

        // Insert all items into the heap
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                maxHeap.push(values[i][j]);
            }
        }

        long long totalSpending = 0;

        // Process each day
        for (int day =  m * n; day >= 1; --day) {
            auto top = maxHeap.top();
            maxHeap.pop();

            

            // Calculate the cost for the day
            totalSpending += (long long)top * day;
        }

        return totalSpending;    
    }
};
