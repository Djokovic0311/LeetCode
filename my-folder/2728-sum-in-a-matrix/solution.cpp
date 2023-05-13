class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        // Define a lambda function for comparison operation in priority queue
        auto comp = [](const auto& a, const auto& b) {
            return a.top() < b.top();
        };
        
        // Initialize a priority queue of priority queues
        priority_queue<priority_queue<int>, vector<priority_queue<int>>, decltype(comp)> pq(comp);

        // Push each row into the priority queue as a priority queue
        for (auto& row : nums) {
            priority_queue<int> rowPQ;
            for (int num : row) {
                rowPQ.push(num);
            }
            pq.push(rowPQ);
        }

        int score = 0;
        vector<priority_queue<int>> temp;
        
        // Perform the operation until the matrix becomes empty
        while (!pq.empty()) {
            // Add the largest number to the score
            score += pq.top().top();
            
            while (!pq.empty()) {
                auto row = pq.top();
                pq.pop();
                
                // Drop the largest number from the row
                row.pop();
                
                // If the row is not empty, push it back into a temporary container
                if (!row.empty()) {
                    temp.push_back(row);
                }
            }
            
            // Put all rows back into the priority queue
            for (auto& row : temp) {
                pq.push(row);
            }
            
            // Clear the temporary container
            temp.clear();
        }
        
        return score;
    }
};
