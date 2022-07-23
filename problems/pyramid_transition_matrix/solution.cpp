class Solution {
public:
    string res;
    bool dfs(string &s, string &ans,vector<vector<char>> &v)
    {
        if(s.size() == ans.size()+1)
        {
            if(ans.size()==0) return true;
            string p;
            if(dfs(ans,p,v)) return true;
            return false;
        }
        int sz = ans.size();
        int x = (s[sz]-'A')*6 + s[sz+1]-'A';
        for(auto &j: v[x])
        {
            ans += j;
            if(dfs(s,ans,v)) return true;
            ans.pop_back();
        }
        return false;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<vector<char>> v(37);
        int n = allowed.size();
        if(n==0) return false;
        for(int i = 0;i<n;i++)
        {
            int x = (allowed[i][0]-'A')*6 + allowed[i][1]-'A';
            v[x].push_back(allowed[i][2]);
        }
        string p;
        return dfs(bottom, p, v);
    }
};