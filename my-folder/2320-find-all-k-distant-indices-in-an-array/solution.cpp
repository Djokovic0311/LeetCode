class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> res;
        set<int> tmp;
        for(int i = 0; i < n; i++) {
            if(nums[i] == key) {
                int l = max(0, i-k);
                int r = min(n-1, i+k);
                for(int j = l; j <= r; j++) {
                    tmp.insert(j);
                }
            }
        }
        for(auto item : tmp) {
            res.push_back(item);
        }
        return res;
    }
};
