class Solution {
public:
    int getLCA(int a, int b) {
        int cnt = 0;
        while(a/2 != b/2) {
            if(a > b) {
                a /= 2;
            }
            else {
                b /= 2;
            }
            cnt++;
        }
        
        if(a!=b) return cnt + 2;
        else return cnt;
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> res;
        
        for(auto q : queries) {
            // cout << getLCA(q[0],q[1]) << endl;
            res.push_back(getLCA(q[0],q[1]) +1);
        }
        return res;
    }
};
