class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& num, int i, int n) {
        if(i == n)
        {res.push_back(num);
         return;}
        for(int j = i; j < n; j++) {
            swap(num[i], num[j]);
            dfs(num, i+1, n);
            swap(num[j], num[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0,nums.size());
        return res;
    }
};
