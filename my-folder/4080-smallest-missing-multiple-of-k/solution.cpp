class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        for (int num : nums) {
            if (num % k == 0) s.insert(num);
        }

        int multiple = k;
        while (true) {
            if (!s.count(multiple)) return multiple;
            multiple += k;
        }
        return -1;
    }
};
