class Solution {
private:
    unordered_map<string, string> parent;
    unordered_map<string, set<string>> sets;

    string find(string word) {
        if (parent.find(word) == parent.end()) parent[word] = word;
        if (parent[word] == word) return word;
        parent[word] = find(parent[word]);
        return parent[word];
    }
    
    vector<string> split(string text) {
        istringstream ss(text); 
        string t; vector<string> res; 
        while (ss >> t) res.push_back(t); 
        return res;
    }
    
    void findCombinations(vector<string>& texts, int index, string comb, vector<string>& res) {
        if (index == texts.size()) {
            res.push_back(comb);
            return;
        }
        if (parent.find(texts[index]) == parent.end()) {
            findCombinations(texts, index + 1, comb + (index == 0 ? "" :" ") + texts[index], res);
        } else {
            string par = find(texts[index]);
            for (const auto& equalword : sets[par]) {
                findCombinations(texts, index + 1, comb + (index == 0 ? "" :" ") + equalword, res);
            }
        }
    }
    
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        vector<string> res;
        for (const auto& pair : synonyms) {
            string parA = find(pair[0]);
            string parB = find(pair[1]);
            if (parA.compare(parB) < 0) parent[parB] = parA;
            else parent[parA] = parB;
        }
        
        // build sets
        for (const auto& entry : parent) {
            string word = entry.first;
            string par = find(word);
            sets[par].insert(word);
        }
        
        // find combinations
        vector<string> texts = split(text);
        findCombinations(texts, 0, "", res);
        sort(res.begin(), res.end());
        return res;
    }
};
