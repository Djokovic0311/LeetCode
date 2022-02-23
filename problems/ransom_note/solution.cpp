class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> dict(26,0);
        for(int i = 0; i < magazine.size(); i++) {
            dict[magazine[i]-'a']++;
        }
        for(int i = 0; i < ransomNote.size(); i++) {
            dict[ransomNote[i]-'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(dict[i] < 0) return false;
        }
        return true;
    }
};