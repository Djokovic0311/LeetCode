class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string res;
        string tmp;
        while(ss >> tmp) {
            reverse(tmp.begin(),tmp.end());
            res += tmp;
            res += " ";
        }
        res.erase(res.size() - 1);
        return res;
    }
};
