class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        int n=nums.size();
        map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                m[i+j].insert(m[i+j].begin(),nums[i][j]);
            }
        }
        for(auto i:m){
            for(int j=0;j<i.second.size();j++){
                ans.push_back(i.second[j]);
            }
        }
        return ans;
    }
};
