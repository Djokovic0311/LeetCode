class WordDistance {
    
private:
    unordered_map<string,vector<int>> mp;
    
public:
    WordDistance(vector<string>& wordsdict) {
        mp.clear();
        for(int i=0 ; i<wordsdict.size() ; ++i) mp[wordsdict[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        int l = 0;
        int r = 0;
        int dist = INT_MAX;
        while(l < mp[word1].size() && r < mp[word2].size()){
            dist = min(dist,abs(mp[word1][l] - mp[word2][r]));
            if(mp[word1][l] <= mp[word2][r]) ++l;
            else ++r;
        }
        return dist;
    }
};
/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */