class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.length();
        int res = 0;

        for(int i = 0, j = 0; j < n; j++) {
            if(mp.find(s[j]) != mp.end()) {
                i = max(mp[s[j]]+1, i);
            }
            res = max(res, j-i+1);
            mp[s[j]] = j;
        }

        return res;
    }
};
