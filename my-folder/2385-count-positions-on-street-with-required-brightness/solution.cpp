class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        vector<int> brightness(n+1, 0);

        // Update brightness array for each street lamp
        for (auto& lamp : lights) {
            int start = max(0, lamp[0] - lamp[1]);
            int end = min(n - 1, lamp[0] + lamp[1]);
            brightness[start]++;
            brightness[end+1]--;
        }

        for(int i = 0; i < n; i++) {
            brightness[i+1] += brightness[i];
            // cout << brightness[i] << " ";
        }

        // Count the number of positions meeting or exceeding the requirement
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (brightness[i] >= requirement[i]) {
                count++;
            }
        }

        return count;        
    }
};
