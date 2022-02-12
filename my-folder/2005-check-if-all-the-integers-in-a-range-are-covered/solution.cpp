class Solution {
public:

bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    int line[52] = {};
    for (auto &r : ranges) {
        line[r[0]] += 1;
        line[r[1] + 1] -= 1;
    }
    for (int i = 1, overlaps = 0; i <= right; ++i) {
        overlaps += line[i];
        if (i >= left && overlaps == 0)
            return false;
    }
    return true;
}
};
