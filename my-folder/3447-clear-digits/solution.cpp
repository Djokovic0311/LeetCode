class Solution {
public:
    string clearDigits(string s) {
        string result = "";
        stack<char> stk;
        int l = s.length();
        for(int i = 0; i < l; i++) {
            if(!isdigit(s[i])) {
                stk.push(s[i]);
            } else {
                if(!stk.empty()) {
                    stk.pop();
                }
            }
        }
        while(!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }

        return result;
    }
};
