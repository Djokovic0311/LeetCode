class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n-1; i++) {
            if(nums[i] == nums[i+1]) 
                nums[i] *= 2, nums[i+1] = 0;
        }
        stack<int> stk;
        for(int num : nums) {
            if(num != 0)
                stk.push(num);
        }
        vector<int> res;
        while(!stk.empty()) {
            // cout << stk.top() << ' ';
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        int n1 = res.size();
        for(int i = 0; i < n-n1; i++) {
            res.push_back(0);
        }
        return res;
    }
};