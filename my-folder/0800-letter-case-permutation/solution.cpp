class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        int count = 0;
        for(int i = 0; i < s.length(); i++) {
            if(islower(s[i]) || isupper(s[i])) {
                count++;
            }
            if(isupper(s[i])){
                s[i]=s[i]-'A'+'a';
            }
        }
        for(int i = 0; i < 1<< count; i++) {
            int bit = 0;
            string word = "";
            for(char c : s) {
                if(islower(c) || isupper(c)) {
                    if(((i>>bit++) & 1)== 1) {
                        word += c-'a'+'A';
                    } else {
                        word += c;
                    }
                } else {
                    word += c;
                }
            }
            res.push_back(word);
        }
        return res;
    }
};
