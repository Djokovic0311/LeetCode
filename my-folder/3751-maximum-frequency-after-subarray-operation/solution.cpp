class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(int num : nums) {
            cnt[num]++;
        }
        auto pick = [&](int p) {
            int res = 0, cur = 0;
            for(int num : nums) {
                if(num == k) {
                    cur--;
                }
                if(num == p) {
                    cur++;
                }
                cur = cur < 0 ? 0 : cur;
                res = max(res, cur);
            }
            return res;
        };
        int res = 0;
        for(const auto& [num, _] : cnt) {
            res = max(res, pick(num));
        }
        return res +cnt[k];
    }
};
