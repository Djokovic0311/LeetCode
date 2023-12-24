class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int sum = 0;
        int presum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if (mp[sum % k]) return true;
            mp[presum%k]++;
            presum = sum;
        }
        return false;        
    }
};
