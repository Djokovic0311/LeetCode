class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++)
        {
            int curr = nums[i];
            if(mp.find(curr) != mp.end())
            {
                if(i - mp[curr] <= k)
                    return true;
            }
            mp[curr] = i;
        }
        return false;
    }
};
