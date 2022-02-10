class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp = {{0,1}};
        int count = 0, sum = 0;
        for(auto n : nums) {
            sum += n;
            if(mp.find(sum-k) != mp.end()) 
                count += mp[sum-k];
            mp[sum]++;
        }
        return count;
    }
};
