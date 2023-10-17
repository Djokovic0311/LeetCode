class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> countA(26, 0), countB(26, 0);

        // Count occurrences of each character in a and b
        for (char ch : a) countA[ch - 'a']++;
        for (char ch : b) countB[ch - 'a']++;
        int res = a.size() + b.size();
        int m = a.size(), n = b.size();
        for (int i = 0; i < 26; ++i) {
            res = min(res, m + n - countA[i] - countB[i]); 
            if (i > 0) {
                countA[i] += countA[i - 1];
                countB[i] += countB[i - 1];
            }
            if (i < 25) {
                res = min(res, m - countA[i] + countB[i]);
                res = min(res, n - countB[i] + countA[i]); 
            }
        }
        return res; 
    }
};
