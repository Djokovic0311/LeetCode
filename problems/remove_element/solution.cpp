class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return NULL;
        int st = 0;
        for(int i = 0; i < nums.size(); i++){
            nums[st] = nums[i];
            if(nums[i] != val){
                st++;
            }
        }
        return st;
    }
};