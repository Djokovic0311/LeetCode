class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(nums[0] > 0) return res;
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1, k = n-1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    res.push_back({nums[i], nums[j],nums[k]});
                    int last_left = nums[j], last_right= nums[k];
                    while(j < k && nums[j] == last_left) j++;
                    while(j < k && nums[k] == last_right) k--;
                } else if(sum < 0) {
                    j++;
                } else {
                    k--;
                }
            } 
        }

        return res;
    }
};
