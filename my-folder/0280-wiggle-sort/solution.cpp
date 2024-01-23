class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // 0 -> 2 -> 1 -> 4 -> 3 -> 6 -> 5
        for(int i = 1; i < n-1; i+=2) {
            swap(nums[i], nums[i+1]);
        }
    }
};
