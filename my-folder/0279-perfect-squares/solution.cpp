class Solution {
public:
    int solve(vector<int>& dp,int n) {
        if (n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        dp[n] = INT_MAX;
        for(int i = 1; i * i <= n; i++) {
            dp[n] = min(dp[n],solve(dp,n-i*i) + 1);
        }
        return dp[n];
    }
    int numSquares(int n) {
        vector <int> dp(n+1, -1);
        int ans = solve(dp,n);
        return ans;
    }
};
