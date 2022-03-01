class Solution {
public:
    string sortString(string s) {
        string res="";
        int a[26]={0},k=0;
        for(int i=0;i<s.length();i++)
        {a[s[i]-'a']++;k++;}
        while(k)
        {
            for(int i=0;i<26;i++)
            {
                if(a[i]>0) { res+=i+'a';k--;a[i]--;}
            }
            for(int i=25;i>=0;i--)
            {
                if(a[i]>0) { res+=i+'a';k--;a[i]--;}
            }
        }
        
        
        return res;
                
    }
};