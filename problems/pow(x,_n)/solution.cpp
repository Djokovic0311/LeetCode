class Solution {
public:
    double myPow2(double x, int n)
    {
        if(n==0)
        {
            return 1;
            
        }
        double res=myPow2(x,n/2);
        if(n&1)
        {
            return x*res*res;
        }
        else
            return res*res;
         
    }
    double myPow(double x, int n) {
        if(n<0)
            x=1/x;
        double ans=myPow2(x,n);
        return ans;
       
    }
};