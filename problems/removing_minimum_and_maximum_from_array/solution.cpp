class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxPos = (int)(max_element(nums.begin(), nums.end()) - (nums.begin()));
        int minPos = (int)(min_element(nums.begin(), nums.end()) - (nums.begin()));
        if(n == 1) return 1;
        int l1 = max(maxPos, minPos) + 1, l2 = n - min(maxPos, minPos), l3 = n - abs(maxPos - minPos) + 1;
        return min(min(l1,l2),l3);
    }
};