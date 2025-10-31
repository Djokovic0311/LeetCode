class Solution {
public:
    int longestBalanced(string s) {
        int res = 0;
        int l = s.length();
        for(int i = 0; i < l; i++) {
            unordered_map<char, int> mp;
            int count = 0;
            int value = 0;
            for(int j = i; j < l; j++) {
                if(mp[s[j]] == 0) count++;
                mp[s[j]]++;
                value = max(value, mp[s[j]]);
                if(count * value == j-i+1) {
                    res = max(res, j-i+1);
                }
            }
        }
        return res;
    }
};
