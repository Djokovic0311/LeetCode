class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        int j=0;
        for(auto i:order)
            mp[i]=j++;
        sort(s.begin(),s.end(),[&](const char &a,const char &b){
            return mp[a]<mp[b];
        });
        return s;        
    }
};
