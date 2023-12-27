class Solution {
public:
    unordered_map<int, int> mp;
    int count = 0;
    void dfs(vector<int>& nums, int n, int k, int i) {
        if(i == n) {
            count++;
            return;
        }
        dfs(nums, n, k, i+1);
        if(mp[nums[i]-k] == 0) {
            mp[nums[i]]++;
            dfs(nums, n, k, i+1);
            mp[nums[i]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        dfs(nums, n, k, 0);
        return count-1;
    }
};
