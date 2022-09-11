class Solution {
public:
    vector<int> grayCode(int m) {
        vector<int> res = {0,1};
        for(int i = 2; i<= m; i++) {
            int n = res.size();
            for(int j=n-1;j>=0;j--){
                res.push_back(res[j]+n);
            }
        }
        return res;
    }
};
