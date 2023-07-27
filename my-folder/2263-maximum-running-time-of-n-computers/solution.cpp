class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
          // Get the sum of all extra batteries.
        std::sort(batteries.begin(), batteries.end());
        long long extra = 0;
        for (int i = 0; i < batteries.size() - n; i++) {
            extra += batteries[i];
        }

        // live stands for the n largest batteries we chose for n computers.
        std::vector<int> live(batteries.end() - n, batteries.end());

        // We increase the total running time using 'extra' by increasing 
        // the running time of the computer with the smallest battery.
        for (int i = 0; i < n - 1; i++) {
            // If the target running time is between live[i] and live[i + 1].
            if (extra < static_cast<long long>(i + 1) * (live[i + 1] - live[i])) {
                return live[i] + extra / static_cast<long long>(i + 1);
            }

            // Reduce 'extra' by the total power used.
            extra -= static_cast<long long>(i + 1) * (live[i + 1] - live[i]);
        }

        // If there is power left, we can increase the running time 
        // of all computers.
        return live[n - 1] + extra / n;       
    }
};
