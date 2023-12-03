class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());

        int addedCoins = 0;
        long long maxReachable = 0;
        for (int coin : coins) {
            while (coin > maxReachable + 1 && maxReachable < target) {
                addedCoins++;
                maxReachable += maxReachable + 1;
            }
            maxReachable += coin;
            if (maxReachable >= target) {
                break;
            }
        }

        while (maxReachable < target) {
            addedCoins++;
            maxReachable += maxReachable + 1;
        }

        return addedCoins;        
    }
};
