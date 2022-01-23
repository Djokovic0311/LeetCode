class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> alphabet = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> res;
        for(auto word: words) {
            string tmp = "";
            for(char c : word) {
                tmp += alphabet[c-'a'];
            }
            res.insert(tmp);
        }
        return res.size();
    }
};
