class Solution {
public:
    int nthUglyNumber(int n) {
        int a = 0, b = 0, c = 0;
        vector<int> res;
        res.push_back(1);
        for(int i = 1; i < n; i++) {
            int tmp = min(res[a]*2, min(res[b]*3, res[c]*5));
            res.push_back(tmp);
            if(tmp == res[a]*2) a++;
            if(tmp == res[b]*3) b++;
            if(tmp == res[c]*5) c++;
        }
        return res[n-1];
    }
};
