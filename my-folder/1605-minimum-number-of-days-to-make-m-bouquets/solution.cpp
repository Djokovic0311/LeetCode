class Solution {
public:
    // Whether it is possible required bouquets with given max time
    bool bouquetPossible(vector<int>& bloom_days, int bloom_day, int m, int k) {
        int bouquets = 0, flowers = 0;
        for(const int& day: bloom_days) {
            if(day <= bloom_day)
                ++flowers;
            else
                flowers = 0;
            if(flowers == k)
                ++bouquets, flowers = 0;
        }
        
        return bouquets >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        // No. of flowers req more than available
        if((long long)m * (long long) k > bloomDay.size())
            return -1;
        
        int low = 0, high = INT_MAX;
        while(low < high) {
            // Candidate bloom date for making req bouquets
            int bloom_day = low + (high - low) / 2;
            if(bouquetPossible(bloomDay, bloom_day, m, k))
                high = bloom_day;
            else
                low = bloom_day + 1;
        }
        
        return high;
    }
};
