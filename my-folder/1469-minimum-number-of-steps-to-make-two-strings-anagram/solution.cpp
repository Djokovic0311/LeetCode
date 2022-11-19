class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mp;
        for(char c : s) {
            mp[c]++;
        }
        for(char c : t) {
            
            mp[c]--;
        }
        int res = 0;
        for(auto it = mp.begin(); it != mp.end(); it++)
            if(it->second > 0)
            res += it->second;
        return res;        
    }
};
