class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int num : nums) mp[num]++;
        int mx = INT_MIN;
        for(auto it : mp) mx = max(mx, it.second);
        int res = 0;
        for(int num : nums)
            if(mp[num] == mx)
                res++;
        return res;
    } 
};
