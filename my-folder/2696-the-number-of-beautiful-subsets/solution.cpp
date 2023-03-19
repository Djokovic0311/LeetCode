class Solution {
public:
    int dfs(vector<int>& nums, int k, int index, vector<int>& subset) {
        int count = 0;
        if (index >= nums.size()) {
            // check if the subset is beautiful
            for (int i = 0; i < subset.size(); i++) {
                for (int j = i + 1; j < subset.size(); j++) {
                    if (abs(subset[i] - subset[j]) == k) {
                        return 0; // not beautiful
                    }
                }
            }
            return 1; // beautiful
        }
        // add current number to subset
        subset.push_back(nums[index]);
        count += dfs(nums, k, index + 1, subset);
        subset.pop_back(); // remove current number from subset
        count += dfs(nums, k, index + 1, subset);
        return count;
    }

int beautifulSubsets(vector<int>& nums, int k, int i = 0, int mask = 0) {
    if (i == nums.size())
        return mask > 0;
    bool bfl  = true;
    for (int j = 0; j < i && bfl ; ++j)
        bfl = ((1 << j) & mask) == 0 || abs(nums[j] - nums[i]) != k;
    return beautifulSubsets(nums, k, i + 1, mask) + 
        (bfl ? beautifulSubsets(nums, k, i + 1, mask + (1 << i)) : 0);
}
};
