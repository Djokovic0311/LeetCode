class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n);
        map<int, int> prefix, suffix;

        // First, add all the elements to the suffix map
        for (int i = 0; i < n; i++) {
            suffix[nums[i]]++;
        }

        for (int i = 0; i < n; i++) {
            // Decrease the count of the current element in the suffix map
            suffix[nums[i]]--;

            // Remove the current element from the suffix map if its count is 0
            if (suffix[nums[i]] == 0) {
                suffix.erase(nums[i]);
            }

            // Add the current element to the prefix map
            prefix[nums[i]]++;

            // Calculate the distinct difference for the current index
            diff[i] = prefix.size() - suffix.size();
        }

        return diff;





        
    }
};
