class Solution {
public:
    string reformat(string s) {
        string n="";
        string a="";
        for(auto i:s)
        {
            if(isdigit(i))
            {
                n+=i;
            }
            else
            {
                a+=i;
            }
        }
        int i=n.size();
        int j=a.size();
        string ans="";
        if(abs(i-j)>1)
        {
            return ans;
        }
        if(i<j)
        {
            swap(n,a);
        }
        int z=min(i,j);int l=0;
        while(l<z)
        {
            ans+=n[l];
            ans+=a[l];l++;
        }
        if(abs(i-j)==1)
        {
            ans+=n[max(i,j)-1];
        }
        return ans;
    }
};
