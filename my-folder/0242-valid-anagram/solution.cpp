class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> dict(26,0);
        int l = s.length();
        if(t.length() != l) return false;
        for(int i = 0; i < l; i++) {
            dict[s[i]-'a']++;
            dict[t[i]-'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(dict[i] != 0) return false;
        }
        return true;
    }
};
