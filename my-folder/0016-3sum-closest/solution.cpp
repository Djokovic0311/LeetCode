class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i ++) {
            int left = i+1, right = n-1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(target - sum) < abs(diff)) {
                    diff = target - sum;
                }
                if(sum < target) {
                    left++;
                } else if(sum > target) {
                    right--;
                } else return target;
            }
        }
        return target - diff;
    }
};
