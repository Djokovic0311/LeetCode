class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> pref(n, 0);
        vector<long long> suff(n, 0);
        stack<int> stk;

        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && maxHeights[i] < maxHeights[stk.top()]) {
                stk.pop();
            }
            if (!stk.empty()) {
                pref[i] = static_cast<long long>(maxHeights[i]) * (i - stk.top()) + pref[stk.top()];
            } else {
                pref[i] = static_cast<long long>(maxHeights[i]) * (i + 1);
            }
            stk.push(i);
        }

        // Clearing the stack for reuse
        while (!stk.empty()) {
            stk.pop();
        }

        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && maxHeights[i] < maxHeights[stk.top()]) {
                stk.pop();
            }
            if (!stk.empty()) {
                suff[i] = static_cast<long long>(maxHeights[i]) * (stk.top() - i) + suff[stk.top()];
            } else {
                suff[i] = static_cast<long long>(maxHeights[i]) * (n - i);
            }
            stk.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, pref[i] + suff[i] - maxHeights[i]);
        }

        return res;
    }
};

