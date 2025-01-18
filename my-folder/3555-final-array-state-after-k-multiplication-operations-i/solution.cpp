class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.first == b.first) {
                return a.second > b.second; 
            }
            return a.first > b.first; 
        };
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;
        for(int i = 0; i < n; i++) {
            pq.push(make_pair(nums[i], i));
        }
        while(k--) {
            auto [val, idx] = pq.top();
            pq.pop();
            pq.push(make_pair(val * multiplier, idx));
        }

        vector<int> res(n);
        while(!pq.empty()) {
            auto [val, idx] = pq.top();
            res[idx] = val;
            pq.pop();
        }

        return res;
    }
};
