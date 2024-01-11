class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, sum = 0;
        int n = nums.size();
        unordered_set<int> st;
        int left = 0, right = 0;
        while(right < n) {
            while(left < right && (st.count(nums[right]) || st.size() >= k)) {
                sum -= nums[left];
                st.erase(nums[left]);
                left++;
            }
            sum += nums[right];
            st.insert(nums[right]);
            if(right-left+1 == k)
                res = max(res, sum);
            right++;
        }

        return res;
    }
};
