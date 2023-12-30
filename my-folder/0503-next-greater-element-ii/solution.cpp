class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(n,-1);
        stack<int> stk;
        for(int i = 2*n-1; i >= 0; i--) {
            while(!stk.empty() && nums[stk.top()] <= nums[i % n]) {
                stk.pop();
            }
            if(!stk.empty()) {
                res[i % n] = nums[stk.top()];
            }
            stk.push(i % n);
        }
        return res;
    }
};
