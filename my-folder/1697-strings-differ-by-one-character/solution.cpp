class Solution {
public:
    bool differByOne(vector<string>& dict) {
    int n = dict.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int diffCount = 0;
            for (int k = 0; k < dict[i].length(); ++k) {
                if (dict[i][k] != dict[j][k]) {
                    diffCount++;
                    if (diffCount > 1) break;  // exit early if more than 1 differing character
                }
            }
            if (diffCount == 1) return true;  // found a pair with 1 differing character
        }
    }
    return false;  // no such pair found        
    }
};
