class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        for(char c : s) {
            freq[c-'a']++;
        }
        int maxVowel = 0, maxCons = 0;
        for(int i = 0; i < 26; i++) {
            if(isVowel('a'+i)) {
                maxVowel = max(maxVowel, freq[i]);
            } else {
                maxCons = max(maxCons, freq[i]);
            }
        }
        return maxVowel+maxCons;
    }
};
