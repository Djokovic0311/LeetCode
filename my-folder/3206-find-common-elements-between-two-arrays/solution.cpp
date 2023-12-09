class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    std::unordered_set<int> nums1Set(nums1.begin(), nums1.end());
    std::unordered_set<int> nums2Set(nums2.begin(), nums2.end());

    int count1 = 0;
    for (int num : nums1) {
        if (nums2Set.count(num) > 0) {
            count1++;
        }
    }

    int count2 = 0;
    for (int num : nums2) {
        if (nums1Set.count(num) > 0) {
            count2++;
        }
    }

    return { count1, count2 };
    }
};
