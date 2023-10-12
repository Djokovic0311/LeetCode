class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long totalWaitTime = 0; // To handle the possibility of large sums
        int currentTime = 0; // The current time
        
        for (auto& customer : customers) {
            int arrival = customer[0];
            int time = customer[1];
            
            if (currentTime <= arrival) {
                // Chef is idle when customer arrives
                totalWaitTime += time;
                currentTime = arrival + time; // Update current time after serving this customer
            } else {
                // Chef is still busy when customer arrives
                totalWaitTime += (currentTime - arrival) + time;
                currentTime += time; // Update current time after serving this customer
            }
        }
        
        return (double) totalWaitTime / customers.size();   
    }
};
