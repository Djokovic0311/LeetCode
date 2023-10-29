class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int result = 0;

        for (int i = 0; i < 32; ++i) {
            int count = 0;
            for (int num : nums) {
                if ((num & (1 << i)) != 0) {
                    ++count;
                }
            }
            if (count >= k) {
                result |= (1 << i);
            }
        }

        return result;        
    }
};
