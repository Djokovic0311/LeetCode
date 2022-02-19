class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        vector<vector<int>> vec(101,vector<int>(0));
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            vec[nums[i]].push_back(i);
        }
        int res = 0;
        for(int i = 0; i < 101; i++) {
            int l = vec[i].size();
            
            if(l > 1) {
                // cout << i << ' ' << l <<endl;
                for(int j = 0; j < l-1; j++) {
                    for(int p = j+1; p < l; p++) {
                        if(vec[i][j] * vec[i][p] % k == 0) res++;
                    }
                }
            }
        }
        return res;
    }
};
