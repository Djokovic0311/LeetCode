class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = wordsDict.size();
        int w1=-1, w2=-1, min_dist = INT_MAX;
        for(int i=0;i<n; i++){
            if(wordsDict[i] == word1) w1 = i;
            else if (wordsDict[i] == word2) w2 = i;
            if(w1!=-1 && w2!=-1) min_dist = min(min_dist, abs(w1-w2));
        }
        return min_dist;            
    }
};