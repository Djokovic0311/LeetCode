class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long result = 0;
        
        for (int peak = 0; peak < n; ++peak) {
            long long currentSum = maxHeights[peak];
            
            int height = maxHeights[peak];
            for (int i = peak - 1; i >= 0; --i) {
                height = min(height, maxHeights[i]);
                currentSum += height;
            }
            
            height = maxHeights[peak];
            for (int i = peak + 1; i < n; ++i) {
                height = min(height, maxHeights[i]);
                currentSum += height;
            }
            
            result = max(result, currentSum);
        }
        
        return result;
    }
};
