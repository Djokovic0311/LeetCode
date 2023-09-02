class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long currentSum = 0;
        long long highestSum = 0;
        unordered_map<int, int> frequencyMap;

        for (int left = 0, right = 0; right < nums.size(); ++right) {
            currentSum += nums[right];
            frequencyMap[nums[right]]++;

            if (right - left + 1 > k) {
                if (--frequencyMap[nums[left]] == 0) {
                    frequencyMap.erase(nums[left]);
                }
                currentSum -= nums[left];
                left++;
            }

            if (right - left + 1 == k) {
                int distinctElementsCount = frequencyMap.size();
                
                if (distinctElementsCount >= m) {
                    highestSum = max(highestSum, currentSum);
                }
            }
        }

        return highestSum;      
    }
};
