class Solution {
public:
    int numWays(string s) {
        vector<int> ones;
        int l = s.length();
        int mod = 1e9+7;
        for(int i = 0; i < l; i++) {
            if(s[i] == '1') {
                ones.push_back(i);
            }
        } 
        int n = ones.size();
        if(n % 3 != 0) return 0;
        if(n == 0) return ((long)(l-1) * (long)(l-2) / 2) % mod; 
        int p1 = ones[n/3-1], p2 = ones[2 * n/3 -1];
        int p3 = ones[n/3], p4 = ones[2 * n/3];
        int zero1 = p3-p1, zero2 = p4-p2;
        return (long)(zero1) * (long)(zero2) % mod;
        // return 0;
    }
};
