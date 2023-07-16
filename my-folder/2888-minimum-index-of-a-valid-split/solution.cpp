class Solution {
public:
    int minimumIndex(vector<int>& nums) {

        int size = nums.size();
        unordered_map<int, int> count;
        int dominant = nums[0];

        for (int i = 0; i < size; ++i) {
            count[nums[i]]++;
            if (count[nums[i]] > count[dominant]) {
                dominant = nums[i];
            }
        }

        vector<int> prefixCount(size, 0);
        vector<int> suffixCount(size, 0);

        prefixCount[0] = (nums[0] == dominant) ? 1 : 0;
        suffixCount[size - 1] = (nums[size - 1] == dominant) ? 1 : 0;

        for (int i = 1; i < size; ++i) {
            prefixCount[i] = prefixCount[i - 1] + (nums[i] == dominant ? 1 : 0);
            suffixCount[size - 1 - i] = suffixCount[size - i] + (nums[size - 1 - i] == dominant ? 1 : 0);
        }

        for (int i = 0; i < size - 1; ++i) {
            if (prefixCount[i] * 2 > i + 1 && suffixCount[i + 1] * 2 > size - i - 1) {
                return i;
            }
        }

        return -1;     
    }
};
