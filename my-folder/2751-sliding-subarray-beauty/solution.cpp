class Solution {
public:
vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    vector<int> ans(nums.size() - k + 1, 0), counter(50, 0);
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0) counter[nums[i] + 50]++;
        if (i - k >= 0 && nums[i - k] < 0) counter[nums[i - k] + 50]--;
        if (i - k + 1 < 0) continue;
        int count = 0;
        for (int j = 0; j < 50; j++) {
            count += counter[j];
            if (count >= x) {
                ans[i - k + 1] = j - 50;
                break;
            }
        }
    }
    return ans;
}
    
};
