class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans;
        long long max_value = nums[0]; // Keep track of the max value in the prefix
        long long sum = nums[0] + max_value; // Initialize the sum with the first element

        ans.push_back(sum);

        for (size_t i = 1; i < nums.size(); ++i) {
            max_value = std::max(max_value, static_cast<long long>(nums[i]));
            sum += nums[i] + max_value; // Add current element + max value to the sum
            ans.push_back(sum);
        }

        return ans;        
    }
};
