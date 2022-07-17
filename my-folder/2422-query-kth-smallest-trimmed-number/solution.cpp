class Solution {
public:
    static bool compare(vector<string>& v1, vector<string>& v2) {
        if(v1[1] != v2[1]) return v1[1] < v2[1];
        else return stoi(v1[0]) < stoi(v2[0]);
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums[0].length(),j = 0,m = nums.size();
        vector<vector<pair<string,int>>>temp(n+1);
        vector<int>res(queries.size());
        for(auto ele : queries)
        {
            if(temp[ele[1]].size() == 0)
            {
                for(int i = 0; i < m; i++)
                {
                    temp[ele[1]].push_back({nums[i].substr(n-ele[1],ele[1]),i});
                }
                sort(temp[ele[1]].begin(),temp[ele[1]].end());
            }
            res[j++] = temp[ele[1]][ele[0]-1].second ;
        }
        return res;
    }
};
