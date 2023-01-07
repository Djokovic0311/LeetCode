class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for(int num : nums) res^= num;
        return res;
    }
};
