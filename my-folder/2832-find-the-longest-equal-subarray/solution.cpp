class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        int res = 0;
        for(auto it : mp) {
            int sz = it.second.size();
            int i = 0, j = 0;
            while(j < sz) {
                while(it.second[j]-it.second[i]-(j-i) > k)
                    i++;
                res = max(res, j-i+1);
                j++;
            }
        } 
        return res;
    }
};
