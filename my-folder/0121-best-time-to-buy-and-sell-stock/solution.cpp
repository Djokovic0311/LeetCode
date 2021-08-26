class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur = 0, min_price = INT_MAX;
        int n = prices.size();
        for(int i = 0; i < n; i++){
            min_price = min(prices[i], min_price);
            cur = max(cur, prices[i] - min_price);
        }
    return cur;
    }
};
