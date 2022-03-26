class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int ones = accumulate(begin(nums), end(nums), 0), zeros = 0, score = 0;
        vector<int> res;
        for (int i = 0; i <= nums.size(); ++i) {
            if (ones + zeros > score) {
                score = ones + zeros;
                res.clear();
            }
            if (ones + zeros == score)
                res.push_back(i);
            if (i < nums.size()) {
                zeros += nums[i] == 0;
                ones -= nums[i];
            }
        }
        return res;
    }
};