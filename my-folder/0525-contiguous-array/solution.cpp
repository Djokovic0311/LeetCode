class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int sum = 0;
        int res = 0;
        mp[0] = -1;
        for(int i = 0; i < n; i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if(mp.find(sum) != mp.end())
                res = max(res, i - mp[sum]);
            else mp[sum] = i;
        }

        return res;
    }
};
