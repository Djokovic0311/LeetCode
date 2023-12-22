class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        map<int, vector<int>>mp;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        for(auto i:mp)
        {   if(i.first%2==0)
            {
                for(int j=i.second.size()-1;j>=0;j--)
                    res.push_back(i.second[j]);
            }
            else
            {
                for(int j=0;j<i.second.size();j++)
                    res.push_back(i.second[j]);
            }
        }
        return res;
    }
};
