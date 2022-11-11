class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] != ']')
                stk.push(s[i]);
            else {
                string cur = "";
                while(!stk.empty() && stk.top() != '[') {
                    cur = stk.top() + cur;
                    stk.pop();
                }
                stk.pop();
                string num = "";
                while(!stk.empty() && isdigit(stk.top())) {
                    num = stk.top() + num;
                    stk.pop();
                }
                int n = stoi(num);
                while(n--){
                    for(int p = 0; p < cur.size() ; p++)
                        stk.push(cur[p]);
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
