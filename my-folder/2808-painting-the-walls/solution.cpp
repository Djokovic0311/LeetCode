class Solution {
public:
    int dp(int idx, int remaining_time, const vector<int>& cost, const vector<int>& time, vector<vector<int>>& memo) {
        if(remaining_time <= 0) return 0;

        // If we've processed all walls
        if (idx >= cost.size()) return 1e9;

        // If the result for this subproblem is already computed
        if (memo[idx][remaining_time] != -1) return memo[idx][remaining_time];
        else {
            int notTake = dp(idx + 1, remaining_time, cost, time, memo);
            int take = cost[idx] + dp(idx + 1, remaining_time - 1 - time[idx], cost, time, memo);
            return memo[idx][remaining_time] = min(take, notTake);
        }
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> memo(501, vector<int>(501, -1));

        return dp(0, n, cost, time, memo);
    }
};
