class Solution {
public:
    vector<string> res;
    void helper(int open, int close, int n, string cur) {
        if(cur.length() == 2 * n) {
            cout << cur << endl;
            res.push_back(cur);
            return;
        }
        if(open < n) helper(open+1, close, n, cur +"(");
        if(close < open) helper(open, close+1, n, cur +")");
    }
    vector<string> generateParenthesis(int n) {
        helper(0,0,n,"");
        return res;
    }
};
