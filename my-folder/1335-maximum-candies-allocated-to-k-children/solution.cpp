class Solution {
public:
    bool canAllocate(vector<int>& candies, long long k, int count) {
        long long children = 0;
        for(int i = 0; i < candies.size(); i++) {
            children += (candies[i]) / count;
        }
        return children >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int maxInPiles = 0;
        for(int i = 0; i < n; i++) {
            maxInPiles = max(maxInPiles, candies[i]);
        }
        int l = 0, r = maxInPiles;

        while(l < r) {
            int mid = l + (r - l)/2+1;
            if(canAllocate(candies, k, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
