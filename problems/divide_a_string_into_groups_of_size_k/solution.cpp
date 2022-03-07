class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int cur = 0;
        int n = s.length();
        while(cur < n-k) {
            res.push_back(s.substr(cur,k));
            cur += k;
        }
        string last = s.substr(cur);
        while(last.length() != k) {
            last += fill;
        }
        res.push_back(last);
        return res;
    }
};