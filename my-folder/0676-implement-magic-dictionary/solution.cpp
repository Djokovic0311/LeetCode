class TrieNode {
public:
    bool isWord = false;
    TrieNode* next[26];
};
class MagicDictionary {
public:
    TrieNode* root;
    MagicDictionary() {
        this->root = new TrieNode();
    }
    
    void buildDict(vector<string> dictionary) {
        for(string word : dictionary) {
            TrieNode* node = root;
            for(char c: word) {
                if(node->next[c-'a'] == NULL) {
                    node->next[c-'a'] = new TrieNode();
                }
                node = node->next[c-'a'];
            }
            node->isWord = true;
        }
    }
    
    bool search(string searchWord) {
        TrieNode* node = root;
        int n = searchWord.size();
        for(int i = 0; i < n; i++) {
            string sub = searchWord.substr(i+1);
            if(!node->next[searchWord[i]-'a']) {
                
                for(int j = 0; j < 26; j++) {
                    TrieNode* curr = node->next[j];
                    if(curr && helper(sub, curr)) {
                        return true;
                    }                    
                }
                return false;
            } else {
                int k = searchWord[i] - 'a';
                for(int j = 0; j < 26; j++) {
                    if(j == k) continue;
                    TrieNode* curr = node->next[j];
                    if(curr && helper(sub, curr))
                        return true;
                }
                node = node->next[searchWord[i]-'a'];
            }
        }
        return false;
    }

    bool helper(string word, TrieNode* node) {
        for(char c : word) {

            if(!node->next[c-'a'])
                return false;
            node = node->next[c-'a'];
        }
        return node->isWord;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
