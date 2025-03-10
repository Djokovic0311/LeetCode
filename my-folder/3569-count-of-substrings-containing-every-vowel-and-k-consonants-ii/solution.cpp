class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    long long countOfSubstrings(string word, int k) {
        long long result = 0;
        int start = 0, end = 0;
        int n = word.length();
        unordered_map<char, int> vowelCount;
        int consonantCount = 0;
        int nextConsonantIndex = n;
        vector<int> nextConsonant(word.size());

        for(int i = n-1; i >= 0; i--) {
            nextConsonant[i] = nextConsonantIndex;
            if(!isVowel(word[i])) {
                nextConsonantIndex = i;
            }
        }

        while(end < n) {
            char c = word[end];
            if(isVowel(c)) {
                vowelCount[c]++;
            } else {
                consonantCount++;
            }

            while(consonantCount > k) {
                char startLetter = word[start];
                if(isVowel(startLetter)) {
                    vowelCount[startLetter]--;
                    if(vowelCount[startLetter] == 0) {
                        vowelCount.erase(startLetter);
                    }
                } else {
                    consonantCount--;
                }
                start++;
            }

            while(vowelCount.size() == 5 && consonantCount == k && start < n) {
                result += nextConsonant[end] - end;
                char startLetter = word[start];
                if(isVowel(startLetter)) {
                    vowelCount[startLetter]--;
                    if(vowelCount[startLetter] == 0) {
                        vowelCount.erase(startLetter);
                    }                    
                } else {
                    consonantCount--;
                }
                start++;
            }

            end++;
        }
        return result;
    }
};
