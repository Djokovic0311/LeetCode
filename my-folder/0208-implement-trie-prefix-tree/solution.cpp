class Trie {

private:

struct TrieNode{
    struct TrieNode *child[26];
    bool isEnd;
};
TrieNode* node;
public:

Trie() {
    node=new TrieNode();
}

void insert(string word) {
    TrieNode* cur=node;
    for(char c: word){
        if(cur->child[c-'a']==NULL) cur->child[c-'a']=new TrieNode();
        cur=cur->child[c-'a'];
    }
    cur->isEnd=true;
}

bool search(string word) {
    TrieNode* cur=node;
    for(char c: word){
        if(cur->child[c-'a']==NULL)return false;
        cur=cur->child[c-'a'];
    }
    if(cur->isEnd==true) return true;
    return false;
}

bool startsWith(string prefix) {
    TrieNode* cur=node;
    for(char c: prefix){
        if(cur->child[c-'a']==NULL)return false;
        cur=cur->child[c-'a'];
    }
    return true;
}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
