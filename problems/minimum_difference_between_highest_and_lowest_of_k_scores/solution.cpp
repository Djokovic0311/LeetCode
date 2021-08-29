class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        int n = nums.size();
        for(int i = k-1; i < n; i++){
            mini = min(mini, nums[i] - nums[i-k+1]);
            cout << mini << endl;
        }
        return mini;
    }
};