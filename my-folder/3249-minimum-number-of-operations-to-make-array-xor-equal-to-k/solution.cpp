class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorSum = 0;
        // Calculate XOR of all elements
        for (int num : nums) {
            xorSum ^= num;
        }
        // If XOR is already k, no operations are needed
        if (xorSum == k) {
            return 0;
        }
        // Count the number of different bits between xorSum and k
        int operations = 0;
        for (int i = 0; i < 32; ++i) { // Assuming 32-bit integers
            if (((xorSum >> i) & 1) != ((k >> i) & 1)) {
                operations++;
            }
        }
        return operations;
    }
};
