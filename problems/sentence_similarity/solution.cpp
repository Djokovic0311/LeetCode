class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int n = sentence1.size(), m = sentence2.size();
        if (n != m) {return false;}
        
        unordered_map<string, unordered_set<string>> similar;
        for (auto & sp : similarPairs)
        {
            similar[sp[0]].insert(sp[1]);
        }
        
        for (int i = 0; i < n; i++)
        {
            auto & a = sentence1[i];
            auto & b = sentence2[i];
            
            if (! (a == b || similar[a].find(b) != similar[a].end() || similar[b].find(a) != similar[b].end()))
            {
                return false;
            }
        }
        return true;
    }
};