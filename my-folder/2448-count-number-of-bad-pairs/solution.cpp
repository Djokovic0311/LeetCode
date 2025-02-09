class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> freq;
        long long goodPairs = 0;
        long long n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int value = nums[i] - i;
            if (freq.count(value)) {
                goodPairs += freq[value]; 
            }
            freq[value]++; 
        }
        
        long long totalPairs = (n * (n - 1)) / 2;
        return totalPairs - goodPairs;
    }
};
