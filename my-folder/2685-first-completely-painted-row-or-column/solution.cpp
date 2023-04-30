class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
                int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, pair<int, int>> positions;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                positions[mat[i][j]] = {i, j};
            }
        }
        
        vector<int> row_count(m, 0);
        vector<int> col_count(n, 0);
        
        for (int i = 0; i < arr.size(); i++) {
            int x = positions[arr[i]].first;
            int y = positions[arr[i]].second;
            
            row_count[x]++;
            col_count[y]++;
            
            if (row_count[x] == n || col_count[y] == m) {
                return i;
            }
        }
        
        return -1; // This should not happen as arr and mat contain all the integers in the range [1, m * n].

    }
};
