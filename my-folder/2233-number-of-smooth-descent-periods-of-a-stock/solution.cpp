class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res = 0;
        int n = prices.size();
        long long i = 0, j = 0;
        while(i < n && j < n) {
            int tmp = 0;

            while(j < n && j-i == prices[i]-prices[j]) j++;
            cout << i << ' ' << j << endl;
            res += (j-i+1) * (j-i) /2;
            i = j;

        }
        return res;
    }
};
