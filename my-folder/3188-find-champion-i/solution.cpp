class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int i = 0; i < n; ++i) {
            bool isChampion = true;
            for (int j = 0; j < n; ++j) {
                if (i != j && grid[i][j] == 0) {
                    isChampion = false;
                    break;
                }
            }
            if (isChampion) return i;
        }

        return -1;        
    }
};
