class TrieNode {
public:
    TrieNode* children[26] = {};
    bool isEndOfWord = false;
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const std::string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isEndOfWord = true;
    }
    
    bool search(const std::string &prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children[c - 'a']) {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return node->isEndOfWord;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
    Trie trie;
    for (const string &word : words) {
        trie.insert(word);
    }
    
    string res;
    for (const string &word : words) {
        bool valid = true;
        for (int i = 1; i < word.size(); ++i) {
            if (!trie.search(word.substr(0, i))) {
                valid = false;
                break;
            }
        }
        if (valid && (word.size() > res.size() || (word.size() == res.size() && word < res))) {
            res = word;
        }
    }
    return res;        
    }
};
