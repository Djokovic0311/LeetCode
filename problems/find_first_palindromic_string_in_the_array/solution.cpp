class Solution {
public:
    bool isvalid(string word) {
        int n = word.length();
        if(n == 0 || n == 1) return true;
        int i = 0, j = n-1;
        while(i <= j) {
            if(word[i] != word[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for(int i = 0; i < n; i++) {
            if(isvalid(words[i])) return words[i];
        }
        return "";
    }
};