class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int lowcount = 0;
        int targetcount = 0;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(nums[i] == target) targetcount++;
            if(nums[i] < target) lowcount++;
        }
        while(targetcount--) {
            res.push_back(lowcount++);
        }
        return res;
    }
};