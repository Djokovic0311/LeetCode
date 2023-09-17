class Solution {
public:
    bool findans(vector<int>& comp, vector<int>& stock, vector<int>& cost, int budget, int answer) {
        long long ans = 0;
        for (int i = 0; i < stock.size(); i++) {
            long long val = comp[i] * (long long) answer;
            if (stock[i] > val) continue;
            else {
                ans += (val - stock[i]) * cost[i];
            }
            if (ans > budget) return false;
        }
        return ans <= budget;
    }

    int find(vector<int>& comp, vector<int>& stock, vector<int>& cost, int budget) {
        long long low = 0;
        long long high = 1e16;
        long long mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (findans(comp, stock, cost, budget, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans = 0;
        for (auto it : composition) {
            ans = max(ans, find(it, stock, cost, budget));
        }
        return ans;
    }
};

