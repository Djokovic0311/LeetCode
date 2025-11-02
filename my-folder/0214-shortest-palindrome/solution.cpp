class Solution {
public:
    string shortestPalindrome(string s) {
        string reversedString = s;
        reverse(reversedString.begin(), reversedString.end());
        for(int i = 0; i < s.length(); i++) {
            if(!memcmp(s.c_str(), reversedString.c_str() + i, s.length() -i)) {
                return reversedString.substr(0, i) + s;
            }
        }
        return reversedString + s;
    }
};
