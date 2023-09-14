class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, int> mp;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                mp[mat[i][j]]++;
        for (const auto& it : mp)
            if (it.second == mat.size())
                return it.first;
        return -1;
    }
};
