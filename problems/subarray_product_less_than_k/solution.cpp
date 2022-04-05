class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		// as all numbers in the array are positive
        if(k <= 1) return 0;
        
		// initialize some vars
        int prod = 1, res = 0, left = 0;
        
		// traversing through each window
        for(int right = 0; right < nums.size(); right++) {
			
			// store the product of elements which we see new in window 
            prod *= nums[right];
    
			// if product is greater than the given k 
			// then slide the window by doing left++ and dividing prod by nums[left] 
            while(prod >= k) {
                prod /= nums[left];
                left++;
            }
			

            res += right - left + 1;
        }
        return res;        
    }
};