class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> stk;
        int res = 0;
        for(int num : nums) {
            while(!stk.empty() && stk.back() > num) {
                stk.pop_back();
            }
            if(num == 0) continue;
            if(stk.empty() || stk.back() < num) {
                res++;
                stk.push_back(num);
            }
        }
        return res;
    }
};
