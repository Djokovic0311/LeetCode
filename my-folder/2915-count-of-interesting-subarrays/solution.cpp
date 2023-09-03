class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, int> prefix_count; // This keeps track of the count of prefix sums we've seen
        int n = nums.size();
        int count = 0; // This count keeps track of the number of elements satisfying nums[i] % modulo == k till ith index
        long long result = 0;
        prefix_count[0] = 1; // This is for the case where the count of the subarray is exactly k (which means we don't need any previous count)

        for(int i = 0; i < n; ++i) {
            if(nums[i] % modulo == k) {
                count++;
            }

            // The key part: If (count - x) % modulo == k, then x = count % modulo.
            int remainder = (count - k + modulo) % modulo;
            if(prefix_count.find(remainder) != prefix_count.end()) {
                result += prefix_count[remainder];
            }
            
            // Update the prefix_count map
            prefix_count[count % modulo]++;
        }

        return result;
    }
};

