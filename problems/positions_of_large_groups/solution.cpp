class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
     vector<vector<int>> res;
        for (int i = 0, j = 0; i < s.size(); i = j) {
            while (j < s.size() && s[j] == s[i]) ++j;
            if (j - i >= 3)
                res.push_back({i, j - 1});
        }
        return res;        
    }
};