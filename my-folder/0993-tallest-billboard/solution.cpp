class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        // dp[taller - shorter] = taller
        unordered_map<int, int> dp;
        dp[0] = 0;
        
        for (int r : rods) {
            // newDp means we don't add r to these stands.
            unordered_map<int, int> newDp(dp);
            
            for (auto entry : dp) {
                int diff = entry.first;
                int taller = entry.second;
                int shorter = taller - diff;
                
                // Add r to the taller stand, thus the height difference is increased to diff + r.
                int newTaller = newDp.count(diff + r) > 0 ? newDp[diff + r] : 0;
                newDp[diff + r] = max(newTaller, taller + r);
                
                // Add r to the shorter stand, the height difference is expressed as abs(shorter + r - taller).
                int newDiff = abs(shorter + r - taller);
                int newTaller2 = max(shorter + r, taller);
                newDp[newDiff] = max(newTaller2, newDp.count(newDiff) > 0 ? newDp[newDiff] : 0);
            }
            
            dp = newDp;
        }
        
        // Return the maximum height with 0 difference.
        return dp.count(0) > 0 ? dp[0] : 0;
    }
};
