class Solution {
public:
    int countVowelSubstrings(string s) {
        int res = 0;
        for(int i=0; i<s.size(); i++){
            unordered_set<char> set;
            for(int j=i; j<s.size(); j++){
                if(!isVowel(s[j])) break;
                set.insert(s[j]);
                if(set.size() == 5) res++;
            }
        }
        return res;
    } 
	
	bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};