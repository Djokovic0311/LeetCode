class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long res = 0;
        vector<int> cols(n,0), rows(n,0);
        int a = n, b = n;
        reverse(queries.begin(),queries.end());
        for(auto q : queries) {
            int type = q[0], index = q[1], val = q[2];
            if(type == 0) {
                if(b>0){
                    if(rows[index]>0)
                        continue;
                    res += val*1LL*b;
                    rows[index] = val;
                }
                a--;
            } else {
                if(a>0){
                    if(cols[index]>0)
                        continue;
                    res += val*1LL*a;
                    cols[index] = val;
                }
                b--;
            }
        }
        return res;
    }
};
