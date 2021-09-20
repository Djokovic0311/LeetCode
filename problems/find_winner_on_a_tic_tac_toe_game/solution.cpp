class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        if (moves.size() < 5) return "Pending";
        int board[3][3] = {{-10, -10, -10}, {-10, -10, -10}, {-10, -10, -10}},
            len = moves.size(), tmpDiag;
        for (int i = 0; i < len; i++) {
            board[moves[i][0]][moves[i][1]] = i & 1;
        }
        tmpDiag = board[0][0] + board[1][1] + board[2][2];
        if (tmpDiag == 0 || tmpDiag == 3) return tmpDiag ? "B" : "A";
        tmpDiag = board[0][2] + board[1][1] + board[2][0];
        if (tmpDiag == 0 || tmpDiag == 3) return tmpDiag ? "B" : "A";
        for (int y = 0, sumRow, sumCol; y < 3; y++) {
            sumRow = sumCol = 0;
            for (int x = 0; x < 3; x++) {
                sumRow += board[y][x];
                sumCol += board[x][y];
            }
            if (sumRow == 0 || sumRow == 3) return sumRow ? "B" : "A";
            if (sumCol == 0 || sumCol == 3) return sumCol ? "B" : "A";
        }
        return len == 9 ? "Draw" : "Pending";
    }
};