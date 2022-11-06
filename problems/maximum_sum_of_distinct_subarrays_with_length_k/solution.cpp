class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> map;
        int left = 0;
        long long res = 0,  sum = 0;
        for(int right = 0; right<nums.size(); right++)
        {
            while(left < right && (map.count(nums[right]) || map.size() >= k))
            {
                sum -= nums[left];
                map.erase(nums[left]);
                left++;
            }
            sum +=nums[right];
            map.insert(nums[right]);

            if (map.size() == k)
                res = max(res, sum);
        }
        return res;
    }
};