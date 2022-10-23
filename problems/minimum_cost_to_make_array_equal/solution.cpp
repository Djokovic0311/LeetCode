class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
           
        long long lo = 1,hi=1e6;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            long long sum1 = 0;
            for(int i =0;i<nums.size();i++){
                long long k = abs(nums[i]-mid);
                sum1+= k*cost[i];  
            }
            
            if(lo==hi)return sum1;
              long long sum3 = 0;
            for(int i =0;i<nums.size();i++){
                long long k = abs(nums[i]-mid-1);
                sum3+= k*cost[i];  
            }
            
             long long sum2 = 0;
            for(int i =0;i<nums.size();i++){
                long long k = abs(nums[i]-mid+1);
                sum2+= k*cost[i];  
            }
            if(sum2>=sum1 && sum1<=sum3)return sum1; 
            if(sum2<sum1){
                hi = mid;
                continue;
            } 
            if(sum3<sum1){
                lo = mid;
                continue;
            }
        }
        
        return 0;   
    }
};