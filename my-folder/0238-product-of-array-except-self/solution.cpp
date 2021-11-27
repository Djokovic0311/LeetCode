class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), temp = 1;
        vector<int> res(n);
        
        // Put in each index in res the product of all elements before it:
        for (int i=0; i<n; i++) {
            res[i] = temp;
            temp *= nums[i];
        }
        
        // Now multiply each one with all the elements after it:
        temp = 1;
        for (int i=n-1; i>=0; i--) {
            res[i] *= temp;
            temp *= nums[i];
        }
        
        return res;
    }
};
