class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        priority_queue<pair<int,int>> pq;
        int res = INT_MIN;

        for(int i=n-1 ; i>=0 ; i--) {
            while(pq.size() && pq.top().second >i+k)
                pq.pop();
            dp[i] = nums[i];
            dp[i] += (pq.size() ? pq.top().first : 0);
            cout << dp[i] << ' ';
            pq.push(make_pair(dp[i],i));

        }
        return dp[0];
    }
};
