class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1, err = 0; i < n; i++)
            if (nums[i] < nums[i-1])
                if (err++ || (i > 1 && i < n - 1 && nums[i-2] > nums[i] && nums[i+1] < nums[i-1]))
                    return false;
        return true;        
    }
};