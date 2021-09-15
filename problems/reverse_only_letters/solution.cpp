class Solution {
public:
    bool isalpha(char c){
        return (c >='a' && c <='z') || (c >='A' && c <= 'Z');
    }
    string reverseOnlyLetters(string s) {
        int n = s.length();
        int i = 0, j = n-1;
        while(i < j) {
            if(isalpha(s[i]) && isalpha(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
                continue;
            }
            if(!isalpha(s[i])) {
                i++;
            }
            if(!isalpha(s[j])) {
                j--;
            }
        }
        return s;
    }
};