class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buy_price = INT_MAX;
        int max_profit = 0;
        for(int p : prices) {
            min_buy_price = min(min_buy_price, p);
            max_profit = max(max_profit, p-min_buy_price);
        }
        return max_profit;
    }
};
