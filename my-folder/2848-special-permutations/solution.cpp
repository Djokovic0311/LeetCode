// class Solution {
// public:
//     const int MOD = 1e9+7;
//     int permute(int mask,int prev,int maxi,vector<int>& nums){
        
//         if(mask==maxi) return 1;
//         int ans=0;
//         for(int i=0;i<nums.size();i++){
//             if(prev>=0 && !(nums[prev] % nums[i]==0 || nums[i] % nums[prev]==0)) 
//                 continue;
//             if(i>0 && nums[i]==nums[i-1] && !(mask & (1<<(i-1)))) 
//                 continue;
//             if(!(mask & (1<<i)))
//                 ans = (ans + permute(mask | (1<<i),i,maxi,nums)) % MOD;
//         }
//         return ans;
//     }
//     int specialPerm(vector<int>& nums) {
        
//         int n = nums.size();
//         int maxi=0;
//         for(int i=0;i<n;i++) 
//             maxi=maxi | (1<<i);
        
//         return permute(0,-1,maxi,nums);

//     }
// };

class Solution {
public:
    const int MOD = 1e9+7;
    vector<vector<int>> memo;
    
    int permute(int mask, int prev, int maxi, vector<int>& nums){
        
        if(mask == maxi) return 1;
        if(prev != -1 && memo[mask][prev] != -1) return memo[mask][prev];
        
        int ans=0;
        for(int i = 0; i < nums.size(); i++){
            if(prev >= 0 && !(nums[prev] % nums[i] == 0 || nums[i] % nums[prev] == 0)) 
                continue;
            if(i > 0 && nums[i] == nums[i-1] && !(mask & (1<<(i-1)))) 
                continue;
            if(!(mask & (1<<i)))
                ans = (ans + permute(mask | (1<<i), i, maxi, nums)) % MOD;
        }
        
        if(prev != -1) memo[mask][prev] = ans;
        return ans;
    }
    
    int specialPerm(vector<int>& nums) {
        
        int n = nums.size();
        int maxi = 0;
        for(int i = 0; i < n; i++) 
            maxi = maxi | (1<<i);
        
        memo = vector<vector<int>>(1<<n, vector<int>(n, -1));
        return permute(0, -1, maxi, nums);
    }
};
