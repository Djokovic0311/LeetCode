class Solution {
public:
    bool isvalid(string s) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int l = s.length();
        if(vowels.find(s[0])!= vowels.end() && vowels.find(s[l-1]) != vowels.end())
            return true;
        return false;
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int cnt = 0;
        for(int i = left; i <= right; i++) {
            if(isvalid(words[i])) cnt++;
        }
        return cnt;
    }
};
