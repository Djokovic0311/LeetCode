class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int res = 0;
        for (int i = 0; i < row.size(); i += 2) {
            int x = row[i];
            if (row[i+1] == (x ^ 1)) continue;
            res++;
            for (int j = i+1; j < row.size(); ++j) {
                if (row[j] == (x^1)) {
                    row[j] = row[i+1];
                    row[i+1] = x^1;
                    break;
                }
            }
        }
        return res;        
    }
};
