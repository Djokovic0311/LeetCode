class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> accessMap;

        // Convert time strings to minutes and store them in the map
        for (const auto& log : access_times) {
            string employee = log[0];
            int time = stoi(log[1].substr(0, 2)) * 60 + stoi(log[1].substr(2, 2)); // Convert HHMM to minutes
            accessMap[employee].push_back(time);
        }

        vector<string> result;

        // Check each employee's access times
        for (auto& entry : accessMap) {
            sort(entry.second.begin(), entry.second.end());

            for (int i = 0; i < entry.second.size(); ++i) {
                int count = 1;
                for (int j = i + 1; j < entry.second.size(); ++j) {
                    // Check if the time difference is less than 60 minutes
                    if (entry.second[j] - entry.second[i] < 60) {
                        count++;
                    } else {
                        break; // Exit the loop if the time difference is 60 minutes or more
                    }
                }
                if (count >= 3) {
                    result.push_back(entry.first);
                    break; // Break to avoid adding the same employee multiple times
                }
            }
        }

        return result;
    }
};
