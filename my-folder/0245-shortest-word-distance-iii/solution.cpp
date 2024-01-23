class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int  n = wordsDict.size();
        int i = 0, j = 0;
        vector<int> idx1, idx2;
        int res = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(wordsDict[i] == word1)
                idx1.push_back(i);
            if(wordsDict[i] == word2)
                idx2.push_back(i);
        }
        if(word1 == word2) {
            for(int i = 0; i < idx1.size()-1; i++) {
                res = min(res, idx1[i+1] - idx1[i]);
            }
        } else {
            while(i < idx1.size() && j < idx2.size()) {
                res = min(res, abs(idx1[i]-idx2[j]));
                if(idx1[i] == idx2[j]) {
                    i++, j++;
                } else if(idx1[i] < idx2[j]) {
                    i++;
                } else j++;
            }
        }

        return res;
    }
};
