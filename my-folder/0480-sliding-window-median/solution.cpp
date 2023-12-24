class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        int n = nums.size();
        multiset<int> lo, hi;

        for(int i = 0; i < n; i++) {
            if(i >= k) {
                if(nums[i-k] <=*lo.rbegin()) {
                    lo.erase(lo.find(nums[i-k]));
                } else {
                    hi.erase(hi.find(nums[i-k]));
                }
            }
            lo.insert(nums[i]);
            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));

            if(lo.size() < hi.size()) {
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }

            if(i >= k-1) {
                res.push_back(k&1 ? *lo.rbegin():((double)(*lo.rbegin()) + (double)(*hi.begin())) * 0.5);
            }
        }

        return res;
    }
};
