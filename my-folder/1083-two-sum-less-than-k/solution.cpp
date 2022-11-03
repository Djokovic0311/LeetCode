class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int maxi=-1;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int sum=0;
        
        while(i<j){
            sum=nums[i]+nums[j];
            if(sum<k){
                maxi=max(maxi,sum);
                i++;
            }
            else{
                j--;
            }
        }
        
        return maxi;
    }
};
