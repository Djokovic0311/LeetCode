class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int sz = ops.size();
        
        for(int i = 0; i < sz; i++) {
            m = min(m, ops[i][0]);
            n = min(n, ops[i][1]);
        }
        return m * n;
    }
};
