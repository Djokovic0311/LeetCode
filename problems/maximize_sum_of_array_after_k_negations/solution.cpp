class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        while (k--) {
            int x = pq.top();
            pq.pop();
            pq.push(-1 * x);
        }
        int res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
        
    }
};