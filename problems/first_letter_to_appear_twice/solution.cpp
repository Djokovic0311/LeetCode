class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> record(26,0);
        for(char c : s) {
            if(record[c-'a'] == 1) return c;
            record[c-'a']++;
        }
        return ' ';
    }
};