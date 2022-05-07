class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack <int> stk;
        int second =  INT_MIN;
        int n = nums.size();
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] < second) {
                return true;
            }
            while(stk.size() > 0 && nums[i] > stk.top()) {
                second = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};