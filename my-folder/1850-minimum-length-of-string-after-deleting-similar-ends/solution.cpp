class Solution {
public:
    int minimumLength(string s) {
        int start = 0;
        int end = s.length() - 1;
        
        // Use two pointers to squeeze the string from both ends
        while (start < end && s[start] == s[end]) {
            // Find the next character that is different from the current end characters
            char currentChar = s[start];
            while (start <= end && s[start] == currentChar) {
                ++start;
            }
            while (end >= start && s[end] == currentChar) {
                --end;
            }
        }
        
        // Calculate remaining string length
        return end - start + 1;        
    }
};
