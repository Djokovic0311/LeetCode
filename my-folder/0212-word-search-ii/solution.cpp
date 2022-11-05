class Solution {
public:
    vector<string> findWords(vector<vector<char>>& b, vector<string>& ws) {
        if (!(row=b.size()) || !(col=b[0].size())) return res;
        
        TN* r = buildTrie(ws);        
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                dfs(b, i, j, r);
        return res;
    }
    
private:
    struct TN {
        TN* next[26];
        string w;
    };
    
    TN* buildTrie(vector<string>& ws) {
        TN* r = new TN();
        for (auto& w : ws) {
            TN* p = r;
            for (char c : w) {
                if (!p->next[c-'a']) p->next[c-'a'] = new TN();
                p = p->next[c-'a'];
            }
            p->w = w;
        }
        return r;
    }
    
    bool inbound(int i, int j) {
        return i>=0 && i<row && j>=0 && j<col;
    }
    
    void dfs(vector<vector<char>>& b, int i, int j, TN* p) {
        if (!inbound(i, j)) return;
        char c = b[i][j];
        if (c == '.' || !p->next[c-'a']) return;
        p = p->next[c-'a'];
        if (!p->w.empty()) {
            res.push_back(p->w);
            p->w.clear();
        }
        
        b[i][j] = '.';
        pair<int,int> dirs[4] = {{0,1},{0,-1},{1,0},{-1,0}};
        for (auto d : dirs) dfs(b, i+d.first, j+d.second, p);
        b[i][j] = c;
    }
    
    int row, col; // board dimensions
    vector<string> res; // words found in board
};

