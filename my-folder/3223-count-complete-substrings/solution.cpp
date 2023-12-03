class Solution {
public:

    int countCompleteSubstrings(string word, int k) {
        int n = word.size();
        vector<int> gap(n+1, 0);
        for(int i = 1; i < n; i++) {
            gap[i+1] = gap[i];
            if (abs(word[i] - word[i-1]) > 2) {
                gap[i+1] += 1;
            }
        }
        vector<int> cur(26, 0);
        vector<vector<int>> acc = {cur};

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            cur[word[i-1]-'a'] += 1;
            acc.push_back(cur);
            
            for(int pre = k; pre <= k*26; pre += k) { // enumerate length k, k*2,  ..., k * 26
                if (i >= pre && gap[i] == gap[i-pre+1]) { // check if any of their char difference > 2
                    bool valid = true;
                    for(int d = 0; d < 26; d++) {
                        int diff = acc.back()[d] - acc[i-pre][d];
                        if (diff != 0 && diff != k) { // all count of chars should be 0 or 26
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        ans += 1;
                    }
                } else {
                    break;
                }
            }
        }
        return ans;
        
    }
};
