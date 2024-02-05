class TrieNode {
public:
    TrieNode* children[26];
    int start = 0;
    int end = 0;
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word) {
            if(!node->children[c-'a']) {
                node->children[c-'a'] = new TrieNode();
            }
            node = node->children[c-'a'];
            node->start++;
        }
        node->end++;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* node = root;
        for(char c : word) {
            if(!node->children[c-'a']) {
                return 0;
            }
            node = node->children[c-'a'];
        }        
        return node->end;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* node = root;
        for(char c : prefix) {
            if(!node->children[c-'a']) {
                return 0;
            }
            node = node->children[c-'a'];
        }        
        return node->start;        
    }
    
    void erase(string word) {
        TrieNode* node = root;
        for(char c : word) {
            node = node->children[c-'a'];
            node->start--;
        }        
        node->end--;       
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
