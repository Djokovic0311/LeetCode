class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int> freq;
        int pairs = 0;

        for (string& word : words) {
            string revWord = word;
            reverse(revWord.begin(), revWord.end());
            pairs += freq[revWord]; 

            freq[word]++;
        }

        return pairs;        
    }
};
