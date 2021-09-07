class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> foundInBoth;
        unordered_set<int> nums2Set(nums2.begin(), nums2.end());
        for (const auto &num : nums1)
        {
          if (nums2Set.find(num) != nums2Set.end())
          {
            foundInBoth.insert(num);
          }
        }
        return vector<int>(foundInBoth.begin(), foundInBoth.end());
    }
};