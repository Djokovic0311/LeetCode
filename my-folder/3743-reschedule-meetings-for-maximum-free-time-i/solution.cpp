class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), res = 0;
        int t = 0;
        for(int i = 0; i < n; i++) {
            t += endTime[i] - startTime[i];
            int left = i < k? 0 : endTime[i-k];
            int right = i == n-1? eventTime: startTime[i+1];
            res = max(res, right-left-t);
            if(i >= k-1) {
                t -= endTime[i-k+1] - startTime[i-k+1];
            }
        }
        return res;
    }
};
