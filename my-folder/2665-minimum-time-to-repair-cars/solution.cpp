class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        int minRank = ranks[0], maxRank = ranks[0];
        unordered_map<int, int> freq;

        for(int rank : ranks) {
            minRank = min(minRank, rank);
            maxRank = max(maxRank, rank);
            freq[rank]++;
        }
        
        long long mintime = 1, maxtime = 1LL * minRank * cars * cars;
        while(mintime < maxtime) {
            long long mid = (maxtime + mintime) / 2;
            long long count = 0;
            for(int rank = 1; rank <= maxRank; rank++) {
                count += freq[rank] * (long long)sqrt(mid/ (long long) rank);
            }

            if(count >= cars) {
                maxtime = mid;
            } else {
                mintime = mid + 1;
            }
        }
        return mintime;
    }
};
