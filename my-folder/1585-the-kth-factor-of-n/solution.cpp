class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> res;
        for(int i = 1; i * i <= n; i++) {
            
            if(n % i == 0 && i * i != n) {
                
                res.push_back(i);
                res.push_back(n/i);
            }
            else if(i * i == n)
            res.push_back(i);
        }
        sort(res.begin(), res.end());
        if(res.size() < k) return -1;
        return res[k-1];
    }
};
