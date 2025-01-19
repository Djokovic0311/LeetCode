class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int i = 0, l = word.length();
        while(i < l) {
            int repeatedCount = 0;
            char c = word[i];
            while(repeatedCount < 9 && i < l && word[i] == c) {
                repeatedCount++;
                i++;
            }
            comp +=  to_string(repeatedCount) + c;
        }
        return comp;
    }
};
