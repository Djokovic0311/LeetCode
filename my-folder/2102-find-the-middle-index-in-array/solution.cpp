class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        for(int i = 0; i < n; i++) {
            right += nums[i];
        }
        for(int i = 0; i < n; i++) {
            int middle = nums[i];
            right -= middle;
            if(i > 0) left += nums[i-1];
            if(left == right) return i;
        }
        return -1;
    }
};
