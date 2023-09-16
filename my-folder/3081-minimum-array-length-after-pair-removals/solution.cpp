class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2;
        int left = 0, right;
        if(n % 2 == 0) right = mid;
        else right = mid+1;
        int res = 0;
        while(left < n && right < n) {
            if(nums[left] < nums[right]) {
                res++;
                left++;
            }
            right++;
        }
        
        return n-res*2;
    }
};
