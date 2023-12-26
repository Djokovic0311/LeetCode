class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        bool status;
        int m = board.size(), n = board[0].size();
        if(idx == word.length()) {
            cout << i << " " << j << endl;
            return true;
        }
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx])
            return false;
        
        board[i][j] = '0';
        
        status = dfs(board, word, i+1, j, idx+1) || dfs(board, word, i-1, j, idx+1) || dfs(board, word, i, j+1, idx+1) || dfs(board, word, i, j-1, idx+1);
        board[i][j] = word[idx];

        return status;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        bool flag = false;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dfs(board,word,i,j,0)) return true;
            }

                
        }

        return false;
    }
};
