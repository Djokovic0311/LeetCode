class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;
        int l = s.length();
        int i = 0;
        for(int i =0; i < l; i++) {
            if(s[i] != ')') {
                stk.push(s[i]);
            } else {
                string tmp = "";
                while(!stk.empty() && stk.top() != '(') {
                    tmp += stk.top();
                    stk.pop();
                }
                if(!stk.empty()) stk.pop(); // pop "(" from stack
                for (int j = 0; j < tmp.length(); j++) {
                    stk.push(tmp[j]);
                }
                cout << tmp << endl;
            }
        }

        string res = "";
        while(!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }

        return res;
    }
};

