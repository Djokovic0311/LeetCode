class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minBuyPrice1 = INT_MAX, minBuyPrice2 = INT_MAX;
        int maxProfit1 = INT_MIN, maxProfit2 = INT_MIN;
        for(int i = 0; i < n; i++) {
            minBuyPrice1 = min(minBuyPrice1, prices[i]);
            maxProfit1 = max(maxProfit1, prices[i] - minBuyPrice1);
            minBuyPrice2 = min(minBuyPrice2, prices[i] - maxProfit1);
            maxProfit2 = max(maxProfit2, prices[i] - minBuyPrice2);
        }
        return maxProfit2;
    }
};
