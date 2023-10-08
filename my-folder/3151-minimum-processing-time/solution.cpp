class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.rbegin(), tasks.rend());

        int n = processorTime.size();

        int maxFinishTime = 0;
        for (int i = 0; i < n; ++i) {
            int finishTime = processorTime[i] + tasks[i * 4]; 
            for (int j = 1; j < 4; ++j) {
                finishTime = max(finishTime, processorTime[i] + tasks[i * 4 + j]);
            }
            maxFinishTime = max(maxFinishTime, finishTime); 
        }
        return maxFinishTime;        
    }
};
