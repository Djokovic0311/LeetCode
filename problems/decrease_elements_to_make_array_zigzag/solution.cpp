class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int i,j,n=nums.size(),ans=0,temp=0;
        if(n < 2) return 0;
        for(i=1;i<n;++i){
            if(i%2){
                if(i+1<n){
                    if(min(nums[i-1],nums[i+1])<=nums[i])
                        ans+=nums[i]-min(nums[i-1],nums[i+1])+1;
                }
                else{
                    if(nums[i-1]<=nums[i])ans+=nums[i]-nums[i-1]+1;
                }
            }
        }
        
        for(i=0;i<n;++i){
            if(i%2==0){
                if(i==0){
                    if(nums[i]>=nums[i+1])
                        temp+=nums[i]-nums[i+1]+1;
                }
                else if(i+1<n){
                    if(min(nums[i-1],nums[i+1])<=nums[i])
                        temp+=nums[i]-min(nums[i-1],nums[i+1])+1;
                }
                else{
                    if(nums[i-1]<=nums[i])temp+=nums[i]-nums[i-1]+1;
                }
            }
        }
        return min(temp,ans);    
    }
};