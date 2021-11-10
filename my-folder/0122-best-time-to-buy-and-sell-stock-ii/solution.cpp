class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int peak, valley;
        int profit = 0;
        for(int i = 0; i < n; i++) {
            while(i < n-1 && prices[i] >= prices[i+1]) i++;
            valley = prices[i];
            while(i<prices.size()-1 && prices[i]<=prices[i+1])i++;
            peak = prices[i];
            profit += peak-valley;
        }
        return profit;
    }
};
