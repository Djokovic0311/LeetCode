class Solution {
public:
    string digitSum(string s, int k) {
        string res = "";
        res = s;
        while(res.length() > k) {
            string tmp = "";
            for(int i = 0; i < res.length(); i += k) {
                int end = min(int(res.length())-1, i+k-1);
                int cur = 0;
                for(int j = i; j <=end; j++) {
                    cur += res[j] - '0';
                }
                tmp += to_string(cur);
            }
            res = tmp;
            cout << res << endl;
        }
        return res;
    }
};