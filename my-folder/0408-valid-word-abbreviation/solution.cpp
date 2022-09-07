class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0, num = 0;
        for(int i = 0; i < abbr.size(); i++) {
            if(isdigit(abbr[i])) {
                if(abbr[i] == '0' && num == 0) return false;        // check leading zero
                num = 10 * num + abbr[i] - '0';
            }
            else {
                j += num;
                num = 0;
                if(j >= word.size() || abbr[i] != word[j]) 
                    return false;
                j++;
            }
        }
        j += num;
        return j == word.size();        
    }
};
