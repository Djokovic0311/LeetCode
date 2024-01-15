class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0;
        int small = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) count++;
            if(nums[i] < target) small++;
        }
        vector<int> res;
        for(int i = small; i < small+count; i++) {
            res.push_back(i);
        }
        return res;
    }
};
