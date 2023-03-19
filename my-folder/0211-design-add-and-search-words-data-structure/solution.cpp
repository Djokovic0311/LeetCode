class TrieNode
{
public:
    bool is_leaf;
    TrieNode* children[26];
    TrieNode()
    {
        is_leaf = false;
        memset(children, 0, sizeof(children)); 
    }
};

class WordDictionary
{
public:
    WordDictionary()
    {
        root = new TrieNode();
    }
    void addWord(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->is_leaf = true;
    }
    bool search(string word)
    {
        return search(word, root, 0);
    }

private:
    TrieNode *root;

    bool search(string word, TrieNode *node, int pos)
    {
        if(pos == word.size())
            return node->is_leaf;
        if (word[pos] != '.'){
            node = node->children[word[pos] - 'a'];
            return node && search(word, node, pos + 1);
        }
        for (int i = 0; i < 26; i++)
            if(node->children[i] && search(word, node->children[i], pos + 1))
                return true;
        return false;        
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
