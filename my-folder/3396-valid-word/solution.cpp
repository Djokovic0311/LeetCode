class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    bool isDigit(char c) {
        return (c >= '0' && c <= '9');
    }
    bool isChar(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    bool isValid(string word) {
        bool hasVowel = false, hasConsonant = false;
        if(word.length() < 3) return false;
        for(char c : word) {
            if(!(isDigit(c) || isChar(c))) return false;
            if(isVowel(c)) hasVowel = true;
            else if(isChar(c))hasConsonant = true;
        }
        return hasConsonant && hasVowel;
    }
};
