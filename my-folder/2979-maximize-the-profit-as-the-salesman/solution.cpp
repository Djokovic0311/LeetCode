class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
    vector<int> dp(n, 0);

    // Sort offers based on their end position
    sort(offers.begin(), offers.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int j = 0;  // Pointer for iterating through the offers
    for (int i = 0; i < n; ++i) {
        // If we don't sell the house
        dp[i] = i > 0 ? dp[i-1] : 0;

        // Check all offers ending at house i
        while (j < offers.size() && offers[j][1] == i) {
            int prev = offers[j][0] - 1;
            int gain = offers[j][2] + (prev >= 0 ? dp[prev] : 0);
            dp[i] = max(dp[i], gain);
            j++;
        }
    }

    return dp[n-1];        
    }
};
