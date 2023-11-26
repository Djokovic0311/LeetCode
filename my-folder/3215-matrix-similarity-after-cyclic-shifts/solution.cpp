class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> original(mat);

        for (int i = 0; i < m; ++i) {
            cyclicShift(mat[i], k, i % 2 != 0);
        }

        return mat == original;
    }
    
    void cyclicShift(vector<int>& row, int k, bool isRight) {
        int n = row.size();
        k %= n;
        if (k == 0) return;

        if (isRight) {
            reverse(row.begin(), row.end());
            reverse(row.begin(), row.begin() + k);
            reverse(row.begin() + k, row.end());
        } else {
            reverse(row.begin(), row.begin() + k);
            reverse(row.begin() + k, row.end());
            reverse(row.begin(), row.end());
    }
}

};
