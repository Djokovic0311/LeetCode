class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int s : stones)
            sum += s;
        int target = sum/2;
        vector<int> dp(target+1, 0);
        for(int stone : stones) {
            for(int j = target; j >= stone; j--) {
                dp[j] = max(dp[j], stone + dp[j - stone]);
            }
        }
        return sum - 2 * dp[target];

    }
};
