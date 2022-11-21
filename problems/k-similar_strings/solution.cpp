class Solution {
public:
    int kSimilarity(string s1, string s2) {
        queue<string> q;
        unordered_map<string,int> mp;
        string a = "", b = "";
        int n = s1.length();
        for(int i =0; i < n; i++) {
            if(s1[i] != s2[i])
                a += s1[i], b += s2[i];
        }
        int ans = -1;
        q.push(a);
        // mp[a] = 0;
        
        while(!q.empty()){
            int n = q.size();
            ++ans;
            
            while(n--)
            {
                string temp = q.front();
                q.pop();

                if(temp == b) return ans;

                for(int i=ans; i<temp.length(); i++)
                {
                    for(int j=i+1; j<temp.length(); j++)
                    {
                        swap(temp[i], temp[j]);
                        if(mp.find(temp) == mp.end() and temp[ans] == b[ans])
                            mp[temp]=1, q.push(temp);
                        swap(temp[i], temp[j]);
                    }
                }
            }
        }
        return mp[b];
    }
};