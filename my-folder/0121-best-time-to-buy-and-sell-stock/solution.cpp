class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = INT_MAX, mx = 0;
        int n = prices.size();
        for(int i = 0; i < n; i++) {
            mi = min(mi, prices[i]);
            mx = max(mx, prices[i]-mi);
        }
        return mx;       
    }
};
