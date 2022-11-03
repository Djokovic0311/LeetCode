class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
         long long int runningsum, n=nums.size();
         vector<long long int> sums(n,0);
         runningsum=sums[n-1]=nums[n-1];
         for(int i=n-2;i>=0;i--){
             runningsum+=nums[i];
             sums[i]=runningsum;
             // cout << sums[i] << " ";
         }
         if(m==1) return sums[0];
         vector<vector<long long int>> dp(n,vector<long long int>(m+1,2147483648));
         dp[n-1][1]=nums[n-1];    //initialisation
         for(int i=n-2;i>0;i--){
             int j=1;             //start calculating for all m in possible range
             while(j<m&&j<=n-i){
                 if(j==1) dp[i][1]=sums[i]; //no partition
                 else{
                     for(int k=i+1;k<n;k++){ // deciding on numb of elems to be include in the set with starting elem
                         dp[i][j]=min(dp[i][j],(max(sums[i]-sums[k],dp[k][j-1]))); 
                     }
                 }
                 j++;
             }
         }
         for(int k=1;k<n;k++){
             dp[0][m]=min(max(sums[0]-sums[k],dp[k][m-1]),dp[0][m]);
         }
         return dp[0][m];
        
    }
};