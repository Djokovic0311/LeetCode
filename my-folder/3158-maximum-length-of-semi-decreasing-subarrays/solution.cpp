class Solution {
public:
    int maxSubarrayLength(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        for(int i = n-1; i>= 0; i--) {
            if(stk.empty() || nums[stk.top()] > nums[i]) {
                stk.push(i);
            }
        }
        int res = 0;
        int i = 0;
        int curr_min = INT_MIN;
        while(i < n && !stk.empty()) {
            while(!stk.empty() && stk.top() <= i) {
                // j should be after i
                stk.pop();
            }
            if(nums[i] > curr_min) {
                curr_min = nums[i];
                while(!stk.empty() && nums[stk.top()] < curr_min) {
                    res = max(res, stk.top() - i + 1);
                    stk.pop();
                }
            }
            i++;
        }
        return res;
    }
};
