class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int n=nums.size(),ma=INT_MIN,mi=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ma=max(ma,nums[i]);
            mi=min(mi,nums[i]);
        }
        return max(0,ma-mi-2*k);        
    }
};