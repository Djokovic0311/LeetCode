class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> dict(26,0);
        int n = s.length();
        for(int i = 0; i < n; i++) {
            dict[s[i]-'a']++;
        }
        for(int i = 0; i < n; i++) {
            if(dict[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};
