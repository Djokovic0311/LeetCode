class Solution {
public:
 int solve(int i,vector<vector<int>>&p, int k,vector<vector<int>> &dp){
        if(i>=p.size() || k<=0) return 0;     //Base Case-> if piles completed or k coins taken
        if(dp[i][k]!=-1) return dp[i][k];
        int fur = solve(i+1,p,k,dp), cur=0;   // skip current pile
        
        for(int idx=0;idx<p[i].size() && idx<k; idx++){  // check for current pile 
            cur += p[i][idx];
            fur = max(fur, cur+solve(i+1,p,k-idx-1,dp));  // recursive call for further piles
        }
        return dp[i][k]=fur;                 // update dp
    }
    
    int maxValueOfCoins(vector<vector<int>>& p, int k) {
        vector<vector<int>> dp(p.size(), vector<int>(k+1,-1));
        return solve(0,p,k,dp);
    }
};
