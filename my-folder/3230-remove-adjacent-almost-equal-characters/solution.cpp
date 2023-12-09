class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n = word.length();
        int operations = 0;

        for (int i = 0; i < n - 1; ++i) {
            if (word[i] == word[i + 1] || abs(word[i] - word[i + 1]) == 1) {
                operations++;
                i++; 
            }
        }

        return operations;        
    }
};
