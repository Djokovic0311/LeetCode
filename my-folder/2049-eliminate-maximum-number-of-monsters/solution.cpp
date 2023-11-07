class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> times(n);
        for (int i = 0; i < n; ++i) {
            // Calculate the time for each monster to reach the city
            times[i] = static_cast<double>(dist[i]) / speed[i];
        }
        
        // Sort the times
        sort(times.begin(), times.end());
        
        int result = 0;
        for (int i = 0; i < n; ++i) {
            // If the current time is less than or equal to result, you lose
            // because the monster reaches the city before or exactly when
            // your weapon is charged.
            if (times[i] <= result) {
                break;
            }
            // Eliminate one monster
            ++result;
        }
        
        return result;        
    }
};
