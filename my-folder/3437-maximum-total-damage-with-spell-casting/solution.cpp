class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> mp;
        for(int p : power) {
            mp[p]++;
        }
        set<int> st(power.begin(), power.end());
        vector<int> elements(st.begin(), st.end());
        sort(elements.begin(), elements.end());
        int n = elements.size();
        vector<long long> dp(n, 0);
        dp[0] = (long long) mp[elements[0]] * elements[0];

        for(int i = 1; i < n; i++) {
            long long damage = mp[elements[i]] * elements[i];
            int prev = upper_bound(elements.begin(), elements.begin()+i, elements[i]-3) - elements.begin() - 1;
            if(prev >= 0) {
                damage += dp[prev];
            }
            dp[i] = max(dp[i-1], damage);
        }
        return dp[n-1];
    }
};
