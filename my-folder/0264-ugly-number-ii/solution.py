class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ans=[1]
        prod_2=prod_3=prod_5=0
        for i in range(1,n):
            a=ans[prod_2]*2
            b=ans[prod_3]*3
            c=ans[prod_5]*5
            m=min(a,b,c)
            ans.append(m)
            if m==a:
                prod_2+=1
            if m==b:
                prod_3+=1
            if m==c:
                prod_5+=1
        return ans[-1]        
