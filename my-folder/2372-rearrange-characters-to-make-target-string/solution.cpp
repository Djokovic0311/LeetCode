class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> record(26,0);
        int n = s.length();
        for(char c : s) {
            record[c-'a']++;
        }
        vector<int> cur(26,0);
        int res = INT_MAX;
        for(char c : target) {
            cur[c-'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(cur[i]!= 0)
            res = min(res,record[i]/cur[i]);
        }
        return res;
    }
};
