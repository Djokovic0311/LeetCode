class Solution {
public:
    double soupServings(int n) {
        if(n == 0)
            return 0.5;
        if(n > 4800)
            return 1.0;
        vector<vector<double>> memo(n + 1, vector<double>(n + 1, -1));
        dp(memo, n, n);
        return memo[n][n];
    }
    double dp(vector<vector<double>> &memo, int A, int B){
        if(!A && !B)
            return 0.5;
        if(!A || !B)
            return !A ? 1.0 : 0;
        if(memo[A][B] != -1)
            return memo[A][B];
        double ans = 0;
        for(int i = 25; i <= 100; i += 25){
            ans += 0.25 * dp(memo, max(0, A - i), max(0, B - 100 + i));
        }
        return memo[A][B] = ans;
    }
};