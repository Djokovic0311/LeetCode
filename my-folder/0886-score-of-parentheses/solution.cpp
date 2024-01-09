class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        stk.push(0);
        for(char c : s) {
            if(c=='(') {
                stk.push(0);
            } else {
                int v = stk.top();
                stk.pop();
                int w = stk.top();
                stk.pop();
                stk.push(w + max(2 * v, 1));
            }
        }

        return stk.top();
    }
};
