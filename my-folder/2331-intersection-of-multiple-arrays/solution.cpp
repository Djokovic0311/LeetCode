class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            for(int num : nums[i]) {
                mp[num]++;
            }
        }
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(it->second == n)
                res.push_back(it->first);
        }
        sort(res.begin(),res.end());
        return res;
    }
};
