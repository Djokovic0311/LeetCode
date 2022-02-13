class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        int num = 1<<n, i = 0;
        while(i < num) {
            vector<int> tmp;
            
            for(int j = 0; j < n; j++) {
                if(i & 1<<j) tmp.push_back(nums[j]);
            }
            res.push_back(tmp);
            i++;
        }
        return res;
    }
    
};