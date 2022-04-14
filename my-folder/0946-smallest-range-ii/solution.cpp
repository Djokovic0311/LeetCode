class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());  
        int maxdiff=nums[nums.size()-1]-nums[0]; 
        int maxelem,minelem; 
        for(int i=1;i<nums.size();i++) 
        {
            maxelem=max(nums[nums.size()-1]-k,nums[i-1]+k); 
            minelem=min(nums[0]+k,nums[i]-k); 
            maxdiff=min(maxdiff,maxelem-minelem);
        }
        return maxdiff;
  }
};
