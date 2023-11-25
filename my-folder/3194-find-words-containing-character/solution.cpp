class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> indices;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].find(x) != std::string::npos) {
                indices.push_back(i);
            }
        }
        return indices;        
    }
};
