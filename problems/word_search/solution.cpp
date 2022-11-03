class Solution {
public:
    string word;
    bool dfs(vector<vector<char>>& board, int i, int j, int n) {
        bool status;
        if(n == word.length()) return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[n])
            return false;
        board[i][j] = '0';
        status = dfs(board, i+1, j, n+1) || dfs(board, i, j+1, n+1) || dfs(board, i-1, j, n+1) || dfs(board, i, j-1, n+1);
        board[i][j] = word[n];
            return status;
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->word = word;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                bool status = dfs(board, i, j, 0);
                if(status == true)
                    return true;
            }
        }
        return false;
    }
};