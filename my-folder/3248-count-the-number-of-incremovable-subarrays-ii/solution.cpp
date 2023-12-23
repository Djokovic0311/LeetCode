
class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
     long long int i,j,k,n=nums.size(),indl=-1,inds=-1,cnt,l,r;
        cnt=0;
        for(i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                cnt++;
            }
        }
        if(cnt==n-1){
            return (n*(n+1))/2;
        }

        cnt=0; 
        for(i=n-2;i>=0;i--){
            if(nums[i]>=nums[i+1]){
                indl=i;
                break;
            }
        }
        cnt=n-indl; //if we start removing from the first element 
        i=0; j=indl+1; 
        while(i<n ||  j<n ){
            if(i>0 && nums[i]<=nums[i-1]){ //if so then we can not remove subarray from starting
                break;
            }
            while(j<n && nums[i]>=nums[j]){ //we are doing this to remove the middle subarray
                j++;
            }
            if(j<n && nums[i]<nums[j] || j>=n && i<n){
                cnt+=(n-j+1);  
            }
            i++;
        }
        return cnt;  
    }
};

