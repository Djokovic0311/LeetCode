class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int e : nums) {
            if(i < 2 || e > nums[i-2]) nums[i++] = e;
        }
        return i;
    }
};