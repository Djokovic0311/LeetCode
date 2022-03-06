class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> v(26,0);
        for(char c : word1) {
            v[c-'a']++;
        }
        for(char c : word2) {
            v[c-'a']--;
        }
        int res = 0;
        for(int i : v) {
            res = abs(i);
            if(res > 3) return false;
        }
        return true;
    }
};