class Solution {
public:
    int possibleStringCount(string word) {
        int result = 1;
        int start = 0, end = 1;
        int l = word.length();
        while(start < l) {
            while(end < l && word[start] == word[end]) {
                end++;
            }
            result += end - start - 1;
            if(end == l) {
                break;
            } else {
                start = end;
                end++;
            }
        }
        return result;
    }
};
