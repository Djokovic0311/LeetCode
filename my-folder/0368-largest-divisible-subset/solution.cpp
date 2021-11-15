class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        vector<int> dp(n,1);
        sort(nums.begin(),nums.end());
        for(int i = 1; i < n ; i++){
            dp[i] = 1;
            for(int j = 0 ; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    dp[i]  = max(dp[i], dp[j] + 1);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            cout << dp[i] << ' ';
        }
        cout << endl;
        int mx = 0,in;
        for(int i = 0; i < n; i++){
            if(dp[i] >= mx){
                mx = dp[i];
                in = i;
            }
        }
        cout << mx;
        vector<int> ans;
        ans.push_back(nums[in]);
        int j = 0;
        for(int i = in-1; i>=0 ; i--){
            if(ans[j] % nums[i] == 0 and dp[i] == mx - ans.size()) {
                ans.push_back(nums[i]);
                j++;
            }
        }
        return ans;
    }
};
