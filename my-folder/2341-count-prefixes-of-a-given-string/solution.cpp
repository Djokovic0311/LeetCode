class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        unordered_map<string,int> mp;
        for(string w : words) {
            mp[w]++;
        }
        int res = 0;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            string sub = s.substr(0,i+1);
            if(mp.find(sub) != mp.end())  {
                res += mp[sub];
            }
        }
        return res;
    }
};
