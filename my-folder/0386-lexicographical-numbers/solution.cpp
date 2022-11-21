class Solution {
public:
    vector<int> lexicalOrder(int n) {
         if(n==0) return {};
        vector<int> res;
        int cur = 1;
        for(int i = 0; i < n; i++) {
            res.push_back(cur);
            cur *= 10;
            while(cur>n) {
                cur /= 10;
                cur++;
                while(cur%10==0) cur/=10;
            }
        }
        return res;       
    }
};
