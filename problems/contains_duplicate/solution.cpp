class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> newset(nums.begin(), nums.end());
    return newset.size()!=nums.size()?true:false;
    }
};