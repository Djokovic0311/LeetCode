class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last_pos = n-1;
        for(int i = n-1; i >= 0; i--) {
            if(i + nums[i] >= last_pos) {
                last_pos = i;
            }
        }
        return last_pos == 0;
    }
};
