class Solution {
public:
    int equalDigitFrequency(string s) {
        set<string>ans;
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++)
        {
            int arr[10]={0};
            ans.insert(s.substr(i,1));
            for(int j=i;j<n;j++)
            {
                arr[s[j]-'0']++;
                int x=arr[s[j]-'0'];
                bool b=true;
                for(int k=0;k<=9;k++)
                {
                    if(arr[k]!=0 && arr[k]!=x)
                    {
                        b=false;
                    }
                }
                if(b)
                    ans.insert(s.substr(i,j-i+1));
            }
        }
        return ans.size();
    }
};
