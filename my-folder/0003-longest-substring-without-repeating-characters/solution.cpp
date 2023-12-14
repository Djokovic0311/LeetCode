class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.length();
        int res = 0;

        for(int i = 0, j = 0; j < n; j++) {
            if(mp[s[j]] > 0) {
                i = max(mp[s[j]], i);

            }
            res = max(res, j-i+1);
            mp[s[j]] = j+1;
        }

        return res;
    }
};
