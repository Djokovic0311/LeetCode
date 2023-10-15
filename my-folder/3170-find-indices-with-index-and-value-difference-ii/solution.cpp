class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
    map<int, int> m;
    for (int i = indexDifference; i < nums.size(); ++i) {
        m[nums[i - indexDifference ]] = i - indexDifference;
        auto it = m.lower_bound(nums[i] + valueDifference);
        if (it != end(m))
            return {i, it->second };
        it = m.upper_bound(nums[i] - valueDifference);
        if (it != begin(m))
            return {i, prev(it)->second };
    }
    return {-1, -1};
    }
};
