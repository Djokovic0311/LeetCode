class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        int n = s.length();
        for(int i =0;i < n; i++) {
            if(s[i] != ']') {
                stk.push(s[i]);
            } else {
                string tmp = "";
                while(!stk.empty() && stk.top() != '[') {
                    tmp = stk.top() + tmp;
                    stk.pop();
                }
                // pop [
                stk.pop();
                string number = "";
                while(!stk.empty() && isdigit(stk.top())) {
                    number = stk.top() + number;
                    stk.pop();
                }
                int time = stoi(number);
                while(time--) {
                    for(int p = 0; p < tmp.size() ; p++)
                        stk.push(tmp[p]);
                }

            }
        }
        s = "";
        while(!stk.empty()){
            s = stk.top() + s;
            stk.pop();
        }
        return s;  
    }
};
