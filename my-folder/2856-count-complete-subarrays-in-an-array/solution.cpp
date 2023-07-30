class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freqMap;
        unordered_map<int, int> freqCount;
        int distinctCount = 0;
        int result = 0;
        int left = 0;
        
        for (int num : nums) {
            if (freqMap[num]++ == 0) {
                distinctCount++;
            }
        }


        for (int right = 0; right < n; right++) {
            if (freqCount[nums[right]]++ == 0) {
                distinctCount--;
            }
            while (distinctCount == 0) {
                result += n - right;
                if (--freqCount[nums[left]] == 0) {
                    distinctCount++;
                }
                left++;
            }
        }

        return result;
        
    }
};
