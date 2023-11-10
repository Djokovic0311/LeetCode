class Solution {
public:
    bool checkValidString(string s) {
        int l = s.length();
        stack<char> stk, star;
        for(int i = 0;i < l; i++) {
            if(s[i] == '(') {
                stk.push(i);
            } else if(s[i] == '*') {
                star.push(i);
            } else {
                if(!stk.empty()) {
                    stk.pop();
                } else if(!star.empty()) {
                    star.pop();
                } else return false;
            }
        }
        while(!stk.empty() && !star.empty() && star.top() > stk.top())
        {
            stk.pop();
            star.pop();
        }
        return stk.empty();
    }
};
