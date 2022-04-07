class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int diff = 0; 
        vector<int> freq(8); 
        unordered_map<char, int> mp = {{'O', -1}, {' ', 0}, {'X', 1}}; 
        for (int i = 0; i < 3; ++i) 
            for (int j = 0; j < 3; ++j) {
                int x = mp[board[i][j]]; 
                diff += x; 
                freq[i] += x; 
                freq[j+3] += x; 
                if (i == j) freq[6] += x; 
                if (i+j == 2) freq[7] += x; 
            }
        bool xwin = false, owin = false; 
        if (find(freq.begin(), freq.end(), 3) != freq.end()) xwin = true; 
        if (find(freq.begin(), freq.end(), -3) != freq.end()) owin = true; 
        if ((xwin && owin) || (xwin && diff != 1) || (owin && diff != 0))  return false; 
        return 0 <= diff && diff <= 1;         
    }
};
