class Solution {
public:
    int sumCounts(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    
    // Generate all possible subarrays
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            
            std::unordered_set<int> distinct;
            for (int k = i; k <= j; ++k) {
                distinct.insert(nums[k]);
            }
            
            sum += distinct.size() * distinct.size();
        }
    }
    
    return sum;       
    }
};
