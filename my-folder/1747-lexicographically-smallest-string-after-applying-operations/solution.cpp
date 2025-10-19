class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.length();
        string res = s;
        s = s + s;
        vector<int> vis(n);
        for(int i = 0; vis[i] == 0; i = (i+b) % n) {
            vis[i] = 1;
            for(int j = 0; j < 10; j++) {
                int c = b % 2 == 0? 0 : 9;
                for(int d = 0; d <= c ; d++) {
                    string t = s.substr(i, n);
                    for(int p = 1; p < n; p+=2) {
                        t[p] = '0' + (t[p] - '0' + j * a) % 10;
                    }
                    for (int p = 0; p < n; p += 2) {
                        t[p] = '0' + (t[p] - '0' + d * a) % 10;
                    }
                    res = min(res, t);
                }                
            }
        }
        return res;
    }
};
