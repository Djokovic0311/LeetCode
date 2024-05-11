class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;

        for (int i = 0; i < n; ++i) {
            workers.emplace_back((double)wage[i] / quality[i], quality[i]);
        }

        // Sort workers by their wage-to-quality ratio
        sort(workers.begin(), workers.end());

        double minCost = DBL_MAX;
        int sumQuality = 0;
        priority_queue<int> maxHeap;

        for (auto& worker : workers) {
            double ratio = worker.first;
            int q = worker.second;

            sumQuality += q;
            maxHeap.push(q);

            if (maxHeap.size() > k) {
                sumQuality -= maxHeap.top();
                maxHeap.pop();
            }

            // When we have exactly k workers, calculate the total cost
            if (maxHeap.size() == k) {
                minCost = min(minCost, sumQuality * ratio);
            }
        }

        return minCost;        
    }
};
