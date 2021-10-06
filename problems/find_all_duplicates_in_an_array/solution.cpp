class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(mp.find(nums[i]) != mp.end()) {
                res.push_back(nums[i]);
            }
            else mp[nums[i]] = 1;
        }
        return res;
    }
};