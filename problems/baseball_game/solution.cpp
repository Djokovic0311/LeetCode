class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stk;
        int n = ops.size();
        for(int i = 0; i < n; i++) {
            if(ops[i] != "C" && ops[i] != "D" && ops[i] != "+")
                stk.push(stoi(ops[i]));
            else if(ops[i] == "C")
                stk.pop();
            else if(ops[i] == "D")
                stk.push(stk.top() * 2);
            else {
                int tmp = stk.top();
                stk.pop();
                int tmp2 = stk.top();
                stk.push(tmp);
                stk.push(tmp+tmp2);
            }
        }
        int res = 0;
        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};