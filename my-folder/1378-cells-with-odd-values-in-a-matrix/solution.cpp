class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> r(m,0);
        vector<int> c(n,0);
        int l = indices.size();
        for(int i = 0; i < l; i++) {
            r[indices[i][0]]++;
            c[indices[i][1]]++;
        }
        int res =0;
        for(int i =0; i< m; i++) {
            for(int j =0; j < n; j++) {
                if((r[i] + c[j]) % 2 == 1) res++;
            }
        }
        return res;
    }
};
