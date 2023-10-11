class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        
        // Convert languages to sets for easier lookups
        vector<unordered_set<int>> langSet(m);
        for (int i = 0; i < m; ++i) {
            langSet[i] = unordered_set<int>(languages[i].begin(), languages[i].end());
        }
        
        // Find pairs that cannot communicate
        unordered_set<int> cannotTalk;
        for (auto& f : friendships) {
            int u = f[0] - 1, v = f[1] - 1; // Convert to 0-indexed
            bool canCommunicate = false;
            for (int lang : languages[u]) {
                if (langSet[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                cannotTalk.insert(u);
                cannotTalk.insert(v);
            }
        }
        
        // If all pairs can communicate, no teaching needed
        if (cannotTalk.empty()) return 0;
        
        // Count the frequency of each language among the users who cannot communicate
        unordered_map<int, int> freq;
        for (int user : cannotTalk) {
            for (int lang : languages[user]) {
                freq[lang]++;
            }
        }
        
        // Find the language with the maximum frequency
        int maxFreq = 0;
        for (auto& [lang, count] : freq) {
            maxFreq = max(maxFreq, count);
        }
        
        return cannotTalk.size() - maxFreq;        
    }
};
