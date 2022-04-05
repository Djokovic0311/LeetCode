class Solution {
public:
    static bool comp(string a,string b)
    {
        if(a.size()!=b.size())
        return a.size()<b.size();
        else
        return a>b;
    }
    string longestWord(vector<string>& words) {
        vector<string> v;
        unordered_set<string> s;
        int n=words.size(),c;
        for(int i=0;i<n;i++)
        s.insert(words[i]);
        for(int i=0;i<n;i++)
        {
            c=0;
            string str;
            int k;
            for(int j=1;j<=words[i].size();j++)
            {
                str=words[i].substr(0,j);
                k=str.size();
                if(s.find(str)!=s.end())
                c++;
            }
            if(c==k)
            v.push_back(str);
        }
        if(v.size()==0)
        return "";
        sort(v.begin(),v.end(),comp);
        return v[v.size()-1];
    }
};
