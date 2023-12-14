class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int wsz = word.size(), asz = abbr.size();
        if(wsz < asz) return false;   
        int l = 0;    
        for(int i = 0; i < asz;) {
            if(abbr[i] == '0') return false;
            if(isdigit(abbr[i])) {
                int start = i;
                while(i < asz && isdigit(abbr[i])) {
                    i++;
                }
                l += stoi(abbr.substr(start, i-start));
            } else {
                if(word[l] != abbr[i]) return false;
                l++;
                i++;
            }
        }  

        return wsz == l;
    }
};
