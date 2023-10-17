class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
    int n = times.size();
    vector<pair<int, int>> events;  // {time, friend number}, negative friend number means departure
    for (int i = 0; i < n; ++i) {
        events.push_back({times[i][0], i});
        events.push_back({times[i][1], -i - 1});  // We use -i - 1 to distinguish friend 0 from departure event of time
    }
    
    sort(events.begin(), events.end());  // Sort based on time, arrivals before departures
    
    priority_queue<int, vector<int>, greater<int>> availableChairs;  // Min heap to keep track of available chairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs;  // Stores {release time, chair number}
    
    for (int i = 0; i < n; ++i) {
        availableChairs.push(i);  // Initially all chairs are available
    }
    
    for (auto& event : events) {
        // Release chairs that are no longer occupied
        while (!occupiedChairs.empty() && occupiedChairs.top().first <= event.first) {
            availableChairs.push(occupiedChairs.top().second);
            occupiedChairs.pop();
        }

        if (event.second >= 0) {  // Arrival
            int friendNum = event.second;
            int chairNum = availableChairs.top();
            availableChairs.pop();
            if (friendNum == targetFriend) {
                return chairNum;
            }
            occupiedChairs.push({times[friendNum][1], chairNum});
        }
    }

    return -1;     
    }
};
