class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        unordered_set<int> nums_set;
        
        // Add the first target/2 numbers to the list.
        for (int i = 1; i <= target/2 && nums_set.size() < n; ++i) {
            nums_set.insert(i);
        }
        
        // Then fill the remaining numbers.
        for (int i = target/2 + 1; nums_set.size() < n; ++i) {
            if(nums_set.count(target - i) == 0) { // Check if target - i doesn't exist in the list
                nums_set.insert(i);
            }
        }

        long long sum = 0;
        for (int num : nums_set) {
            sum += num;
        }

        return sum;     
    }
};
