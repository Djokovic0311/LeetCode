class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string res;
        stack<string> stk;
        while(ss >> word) {
            stk.push(word);
        }
        while(stk.size() != 1) {
            res += stk.top();
            res += ' ';
            stk.pop();
        }
        res += stk.top();
        return res;       
    }
};
