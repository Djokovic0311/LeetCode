class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int res = -1;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j <= i; j++)
                if(nums[j] == -nums[i]) {
                    res = nums[i];
                    break;
                }
            if(res != -1)
                break;
                    
        }
        return res;
    }
};