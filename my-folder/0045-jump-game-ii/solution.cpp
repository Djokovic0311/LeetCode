class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int cur_end = 0, cur_far = 0;
        for(int i = 0;i < n-1; i++) {
            cur_far = max(cur_far, i + nums[i]);
            if(i == cur_end) {
                res++;
                cur_end = cur_far;
            }
        }

        return res;
    }
};
