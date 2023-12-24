class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> res;
        nums.insert(nums.begin(), lower);
        nums.insert(nums.end(), upper);
        int n = nums.size();

        for(int i = 0; i < n-1; i++) {
            int start = nums[i]+1;
            int end = nums[i+1]-1;
            if(i == 0) {
                start = nums[i];
            }
            if(i == n-2) {
                end = nums[n-1];
            }
            if(start <= end) {
                res.push_back({start, end});
            } 
        }

        return res;
    }
};
