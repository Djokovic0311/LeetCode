class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int> count(32, 0);  // count of powers of 2
        
        for (int num : nums) {
            count[__builtin_ctz(num)]++;
        }

        int operations = 0;
        for (int i = 0; i < 31; ++i) {
            if (target & (1 << i)) {  // if bit i in target is 1
                if (count[i] > 0) {
                    count[i]--;
                } else {
                    // need to find a higher power of 2 to split
                    int j = i + 1;
                    while (j < 31 && count[j] == 0) {
                        j++;
                    }
                    if (j == 31) return -1;  // can't form target
                    while (j > i) {
                        count[j]--;
                        count[j - 1] += 2;
                        operations++;
                        j--;
                    }
                    count[i]--;
                }
            }
            count[i + 1] += count[i] / 2;
            count[i] %= 2;
        }

        if (count[31] * (1LL << 31) < (target & (1LL << 31))) return -1;
        return operations;
    }
};

