class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq (26, 0);
        for(char c : s) {
            freq[c-'a']++;
        }
        int i = 0, j = 25;
        sort(freq.begin(), freq.end());
        while(freq[i] == 0) {
            i++;
        }
        int maxOdd = 0, minEven = 101;
        for(; i < 26; i++) {
            if(freq[i] % 2 != 0) {
                maxOdd = max(maxOdd, freq[i]);
            } else {
                minEven = min(minEven, freq[i]);
            }
        }
        return maxOdd-minEven;
    }
};
