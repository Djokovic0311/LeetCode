class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int beautifulSubstrings(string s, int k) {
        int count = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            int vowels = 0, consonants = 0;
            for (int j = i; j < n; ++j) {
                if (isVowel(s[j])) {
                    ++vowels;
                } else {
                    ++consonants;
                }

                if (vowels == consonants && (vowels * consonants) % k == 0) {
                    ++count;
                }
            }
        }

        return count;        
    }
};
