class Solution {
public:
   long long  count(char ch, string &s){
      long long cnt =0 , res = 0,n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]==ch){
                res+=(cnt)*(cnt+1)/2;
                cnt=0;
            }
            else
                cnt++;
        }
       
        res+=(cnt)*(cnt+1)/2;
        return n*(n+1)/2 - res;
 }
    
    long long appealSum(string s) {
     long long ans=0;  
        for(char ch='a';ch<='z';ch++)
            ans+=count(ch,s);
      return ans;
        
    }
};