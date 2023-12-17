class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<std::vector<int>> result;
        vector<int> currentGroup;

        for (int num : nums) {
            if (currentGroup.empty() || (num - currentGroup[0] <= k && currentGroup.size() < 3)) {
                currentGroup.push_back(num);
                if (currentGroup.size() == 3) {
                    result.push_back(currentGroup);
                    currentGroup.clear();
                }
            } else {
                // Cannot satisfy the condition
                return {};
            }
        }

        // Check if there are any leftover elements
        if (!currentGroup.empty()) {
            return {};
        }

        return result;        
    }
};
