class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> seen; 
        for (auto word : words) {
            string even, odd; 
            for (int i = 0; i < word.size(); ++i) {
                if (i&1) odd.push_back(word[i]); 
                else even.push_back(word[i]); 
            }
            sort(even.begin(), even.end()); 
            sort(odd.begin(), odd.end()); 
            seen.insert(even+odd); 
        }
        return seen.size();         
    }
};
