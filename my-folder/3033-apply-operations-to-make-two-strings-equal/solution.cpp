class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        int cnt = 0;
        for (auto x : s1) if (x == '1') cnt++;
        for (auto x : s2) if (x == '1') cnt--;
        
        if (cnt % 2 != 0) return -1;
        
        vector <int> a;
        for (int i = 0; i < s1.length(); i++) if (s1[i] != s2[i]) a.push_back(i);
        
        int n = a.size();
        vector<int> dp(n + 1, 10000000);
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++){
            dp[i] = dp[i - 1] + x;
            if (i >= 2) dp[i] = min(dp[i], dp[i - 2] + 2 * (a[i - 1] - a[i - 2]));
        }
        
        return dp[n] / 2;
    }
};
