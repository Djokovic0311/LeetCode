class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int left = 0;
        for(int j = 0; j < n; j++) {
            if(left * 2 == sum - nums[j]) return j;
            left += nums[j];
            
        }
        return -1;
    }
};