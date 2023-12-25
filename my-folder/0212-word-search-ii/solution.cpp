class Solution {
private:
    int rows, cols;
    vector<string> res;
    struct TrieNode {
        TrieNode* nxt[26];
        string word;
    };
    TrieNode* build(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string s: words) {
            TrieNode* p = root;
            for(char c : s) {
                // cout << c << " " ;
                if(!p->nxt[c-'a']) {
                    p->nxt[c-'a'] = new TrieNode();
                }
                p = p->nxt[c-'a'];
            }    
            // cout << endl;
            p->word = s;
        }

        return root; 
    }
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p) {
        if(!(i >= 0 && i < rows && j >= 0 && j < cols)) return;
        char c = board[i][j];
        
        if(c == '*' || !p->nxt[c-'a']) return;
        p = p->nxt[c-'a'];
        if(!p->word.empty()) {
            res.push_back(p->word);
            p->word.clear();
        }
        board[i][j] = '*';
        pair<int,int> dirs[4] = {{0,1},{0,-1},{1,0},{-1,0}};
        for (auto d : dirs) dfs(board, i+d.first, j+d.second, p);
        board[i][j] = c;
        
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = board[0].size();
        TrieNode* tn = build(words);
        cout << "yes" << endl;
        for(int i = 0; i < rows; i++) {
            for(int j= 0; j < cols; j++) {
                dfs(board, i, j, tn);
            }
        }

        return res;
    }
};
