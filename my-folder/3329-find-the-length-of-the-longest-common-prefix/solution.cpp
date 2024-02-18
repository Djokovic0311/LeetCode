class TrieNode {
public:
    vector<shared_ptr<TrieNode>> children;
    bool isEndOfWord;

    TrieNode() : children(10), isEndOfWord(false) {}
};

class Solution {
public:
    void insert(shared_ptr<TrieNode> root, const string& key) {
        shared_ptr<TrieNode> pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - '0';
            if (!pCrawl->children[index]) {
                pCrawl->children[index] = make_shared<TrieNode>();
            }
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord = true;
    }

    int search(shared_ptr<TrieNode> root, const string& key) {
        shared_ptr<TrieNode> pCrawl = root;
        int length = 0;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - '0';
            if (!pCrawl->children[index]) {
                break;
            }
            length++;
            pCrawl = pCrawl->children[index];
        }
        return length;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // Build trie for arr1
        shared_ptr<TrieNode> root = make_shared<TrieNode>();
        for (int num : arr1) {
            insert(root, to_string(num));
        }

        // Search longest common prefix for elements of arr2 in the trie
        int longestPrefix = 0;
        for (int num : arr2) {
            int currentPrefix = search(root, to_string(num));
            longestPrefix = max(longestPrefix, currentPrefix);
        }

        return longestPrefix;
    }
};
