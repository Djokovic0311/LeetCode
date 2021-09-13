class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            if(i < n-1)
                count += min(timeSeries[i+1]-timeSeries[i],duration);
            else
                count += duration;

            
        }
        return count;
    }
};
