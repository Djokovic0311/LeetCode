class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long res = 0;
        int n = tasks.size();
        unordered_map<int, long long> lastDay;  // Map to store the last day a task was completed


        for (int task : tasks) {
            // If the task was completed recently
            if (lastDay.find(task) != lastDay.end() && res - lastDay[task] <= space) {
                res = (long long)lastDay[task] + (long long)space + 1;  // Wait until the required space has passed
            } else {
                res++;  // Proceed to the next day
            }
            lastDay[task] = res;  // Update the last day this task was completed
        }

        return res;        
    }
};
