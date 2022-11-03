class Solution {
public:
    int uniquePaths(int m, int n) {
        int k=m+n-2;
      long  ans=1;
        for(int i=1;i<=n-1;++i){
            
            
           ans=ans*(k-(n-1)+i)/i;
        }
        return (int)ans;
        
    }
};