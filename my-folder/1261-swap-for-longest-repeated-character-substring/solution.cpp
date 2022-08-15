class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size(), result = 0, idx = -1, nums[n];
        unordered_map<int, int> pos;
        for (const auto c : text) ++pos[c];
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j < n and text[j] == text[i]) ++j;
            nums[++idx] = j - i;
            result = (idx > 1 and nums[idx - 1] == 1 and i > 1 and text[i - 2] == text[i]) ? max(result, min(nums[idx] + nums[idx - 2] + 1, pos[text[i]])) : max(result, min(nums[idx] + 1, pos[text[i]]));
            i = j - 1;
        }
        return result;
    }
};
