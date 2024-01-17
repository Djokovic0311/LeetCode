class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp = nums;
        int n = nums.size();
        k %= n;
        for(int i = 0; i < k; i++) {
            nums[i] = nums[i+n-k];
        }

        for(int i = k; i < n; i++) {
            nums[i] = tmp[i-k];
        }
        
    }
};
