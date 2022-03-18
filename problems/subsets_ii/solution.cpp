class Solution {
public:
  
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res = {{}};
        vector<int> curr;
        int size;
        
        for (auto num : nums) {
            size = res.size();
            
            for (int i = 0; i < size; i++) {
                curr = res[i];
                curr.push_back(num);
                if (find(res.begin(), res.end(), curr) == res.end())
                    res.push_back(curr);
            }
        }
        
        return res;
    }
};