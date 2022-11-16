class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, map<int, string>> A;
        unordered_map<string, int> freq;
        int max_count=0; string ret="";
        for(int i=0; i<username.size(); i++)
            A[username[i]][timestamp[i]] = website[i];
        for(auto u:A)
        {
            unordered_set<string> S;
            for(auto it = begin(u.second); it!=end(u.second); it++)
            {
                for(auto it1 = next(it); it1!=end(u.second); it1++)
                {
                    for(auto it2 = next(it1); it2!=end(u.second); it2++)
                        S.insert(it->second + "%" + it1->second + "^" + it2->second);
                }
            }
            for(auto s: S)
                freq[s]++;
        }
        for(auto t:freq)
        {
            if(t.second>=max_count)
            {
                ret = ((ret=="")||(max_count<t.second)) ? t.first : min(ret, t.first);
                max_count = t.second;
            }
        }
        auto it1 = ret.find("%"), it2 = ret.find("^");
        return {ret.substr(0, it1), ret.substr(it1+1, it2-it1-1), ret.substr(it2+1)};        
    }
};
