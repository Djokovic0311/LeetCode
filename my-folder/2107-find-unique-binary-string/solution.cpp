class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
    unordered_set<string> set(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < (1 << n); ++i) {
        string candidate = "";
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                candidate = "1" + candidate;
            } else {
                candidate = "0" + candidate;
            }
        }
        if (set.find(candidate) == set.end()) {
            return candidate;
        }
    }
    return "";         
    }
};
