class Solution {
public:
    int dp[50][50][50];
    int check(int r1,int c1,int r2,int n,vector<vector<int>>&grid){
        int c2=r1+c1-r2;  //r1+c1==r2+c2 => c2=r1+c1-r2;
        if(r1>=n or c1>=n or r2>=n or c2>=n or grid[r1][c1]==-1 or grid[r2][c2]==-1)
          return INT_MIN; //return a false value if base case fails.
        
       if(dp[r1][c1][r2]!=-1) 
         return dp[r1][c1][r2] ; //use of memoisation to record already calculated values
     
        //if one can reach the end then other can also reach the end.
      if(r1==n-1 and c1==n-1)  return grid[r1][c1];
        
        int temp=0;
        
      if(r1==r2 and c1==c2) //if both are on the same cell then only one will collect the 
                             //cherry both can't collect the same cherry.
        temp+=grid[r1][c1];
        
        
     else temp+=grid[r1][c1]+grid[r2][c2]; //both cherries will be added to the total
        
     int a=check(r1+1,c1,r2+1,n,grid)   ; //both move vertically
    int b=check(r1+1,c1,r2,n,grid)   ;     
    int c=check(r1,c1+1,r2,n,grid)   ;          
    int d=check(r1,c1+1,r2+1,n,grid)   ;         
    
      temp+=max(max(a,b),max(c,d)); //max of a,b,c,d
     dp[r1][c1][r2]=temp; //saving the current result
        return temp;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        memset(dp,-1,sizeof(dp));
        return max(0,check(0,0,0,n,grid));
    }
};
