class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n = batteryPercentages.size();
        int testedDevices = 0;

        for (int i = 0; i < n; ++i) {
            if (batteryPercentages[i] > 0) {
                testedDevices++; // Test the device
                // Decrease the battery percentage of subsequent devices
                for (int j = i + 1; j < n; ++j) {
                    batteryPercentages[j] = max(0, batteryPercentages[j] - 1);
                }
            }
            // Move to the next device
        }

        return testedDevices;        
    }
};
