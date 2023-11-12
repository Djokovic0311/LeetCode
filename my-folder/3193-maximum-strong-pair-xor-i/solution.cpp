class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int max_xor = 0;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                int x = nums[i];
                int y = nums[j];

                // Check if it's a strong pair
                if (abs(x - y) <= min(x, y)) {
                    max_xor = max(max_xor, x ^ y);
                }
            }
        }

        return max_xor;        
    }
};
