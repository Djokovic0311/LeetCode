class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        int left = 0, maxLength = 0;

        for (int right = 0; right < nums.size(); ++right) {
            freqMap[nums[right]]++;

            while (freqMap[nums[right]] > k) {
                freqMap[nums[left]]--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;        
    }
};
