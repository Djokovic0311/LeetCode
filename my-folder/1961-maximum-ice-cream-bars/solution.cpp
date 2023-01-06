class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int res = 0;
        sort(costs.begin(), costs.end());
        int i = 0;
        int n = costs.size();
        while(i < n && coins>=costs[i]) {
            res++;
            coins -= costs[i];
            i++;
        }
        return res;
    }
};
