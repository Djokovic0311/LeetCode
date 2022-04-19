class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        unordered_set<int> di;
        for (auto i = 1; i < strs.size(); ++i) {
            for (auto j = 0; j < strs[i].size(); ++j) {
                if (di.count(j) > 0 || strs[i - 1][j] == strs[i][j]) continue;
                if (strs[i - 1][j] > strs[i][j]) {
                    di.insert(j);
                    i = 0;
                }
                break;
            }
        }
        return di.size();        
    }
};
