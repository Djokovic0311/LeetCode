class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        bool flag1 = false, flag2 = false;
        // false:挪前面 true:挪后面
        
        return min(min((nums[n-2]-nums[1]),(nums[n-1]-nums[2])),(nums[n-3]-nums[0]));
    }
};
