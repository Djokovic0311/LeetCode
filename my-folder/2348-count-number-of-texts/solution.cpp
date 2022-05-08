class Solution {
public:
long long mod=1000000007;
    
    long long ans[100001];
    
    long long solve(string &s,int i)
    {
        if(i==s.size())
        {
            return 1;
        }
        
        if(ans[i]!=-1)
        {
            return ans[i];
        }
        
        long long cnt=0;
        
        if(s[i]=='9'||s[i]=='7')
        {
            char c=s[i];
            
            for(int j=i;j<i+4;j++)
            {
                if(s[j]==c)
                {
                    cnt=(cnt+solve(s,j+1))%mod;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            char c=s[i];
            
            for(int j=i;j<i+3;j++)
            {
                if(s[j]==c)
                {
                    cnt=(cnt+solve(s,j+1))%mod;
                }
                else
                {
                    break;
                }
            }
        }
        ans[i]=cnt%mod;
        return ans[i];
    }
    int countTexts(string pressedKeys) 
    {
        memset(ans,-1,sizeof(ans));
        
        long long fans=solve(pressedKeys,0);
        return fans;
    }
};
