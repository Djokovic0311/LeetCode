class Solution {
public:
    int count(int m,int n,int elem)
    {
        int c=0;
        for(int i=1;i<=m;i++)  
        {
            c+=min(n,elem/i);   
        }
        return c;
    }
    int findKthNumber(int m, int n, int k) 
    {
        int l=1;   
        int r=m*n;  
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(l==r)
            {
                return l;
            }
            if(count(m,n,mid)<k)       
            {
                l=mid+1;
            }
            else
            {
                r=mid;       //else we should find on the left of mid. 
            } 
        }
        return l;
    }
};
