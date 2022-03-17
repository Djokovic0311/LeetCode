class Solution {
public:
    void generatePermutations(vector<int> nums, vector<vector<int>>& output, int idx) {
        if(idx == nums.size()) {
            output.push_back(nums);
        }
        for(int i = idx; i < nums.size(); i++) {
            if(i!=idx && nums[i] == nums[idx]) continue;
            swap(nums[i], nums[idx]);
            generatePermutations(nums, output, idx+1);
            // swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        generatePermutations(nums, res, 0);
        return res;
    }
};
