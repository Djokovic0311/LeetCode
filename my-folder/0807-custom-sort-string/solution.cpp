class Solution {
public:

    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for(int i = 0; i < order.length(); i++)
            mp[order[i]] = i;
        sort(s.begin(),s.end(),[&](const char &a,const char &b){
            return mp[a]<mp[b];
        });
        return s;
    }
};
