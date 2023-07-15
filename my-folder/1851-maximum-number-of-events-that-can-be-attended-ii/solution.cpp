class Solution {
public:
typedef vector<int> vi;
typedef vector<vi> vvi;

static bool compare(const vi &a, const vi &b) {
    return a[1] < b[1];
}

int binarySearch(vvi &events, int index) {
    int low = 0, high = index - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (events[mid][1] < events[index][0]) {
            if (events[mid + 1][1] < events[index][0]) {
                low = mid + 1;
            } else {
                return mid;
            }
        } else {
            high = mid - 1;
        }
    }

    return -1;  // Return -1 if there's no compatible event.
}

    int maxValue(vector<vector<int>>& events, int k) {
    // Sort events according to endDay
    sort(events.begin(), events.end(), compare);
    int n = events.size();
    // Create an auxiliary table to store solutions to subproblems
    vector<vector<int>> dp(n, vector<int>(k+1, 0));

    // Fill entries in dp table using a recursive solution
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j == 1) {
                dp[i][j] = max((i ? dp[i-1][j] : 0), events[i][2]);
            } else {
                int l = binarySearch(events, i);
                int inclVal = events[i][2] + (l != -1 ? dp[l][j-1] : 0);
                int exclVal = (i ? dp[i-1][j] : 0);

                dp[i][j] = max(inclVal, exclVal);
            }
        }
    }
    return dp[n-1][k];      
    }
};
