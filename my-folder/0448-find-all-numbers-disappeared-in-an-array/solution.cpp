class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i =0; i < n; i++) {
            int idx = abs(nums[i])-1;
            if(nums[idx] > 0) {
                nums[idx] *= -1;
            }
        }

        for(int i = 1; i <= n; i++) {
            if(nums[i-1] > 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};
