class Solution {
public:
    int calculate(string s) {
        s += "+";
        char lastOperation = '+';
        int lastNumber = 0, currNumber = 0, eval = 0;
        stack<int> stack;
        unordered_map<char,int> sign{{'+', 0}, {'-', 1}, {'*', 2}, {'/', 3}};
        unordered_map<int, char> number{{0, '+'}, {1, '-'}, {2, '*'}, {3, '/'}};

        for(int i = 0; i < s.length(); ++i) {
            if(isdigit(s[i])) {
                currNumber = currNumber*10 + (s[i]-'0');
            } else {
                if(s[i] == '(') {
                    stack.push(eval);
                    stack.push(lastNumber);
                    stack.push(sign[lastOperation]);
                    eval = 0; lastOperation = '+'; lastNumber = 0;
                } else {
                    if(lastOperation == '+') {
                        eval += lastNumber;
                        lastNumber = currNumber;
                    } else if(lastOperation == '-') {
                        eval += lastNumber;
                        lastNumber = -currNumber;
                    } else if(lastOperation == '*') {
                        lastNumber = lastNumber*currNumber;
                    } else if(lastOperation == '/') {
                        lastNumber = lastNumber/currNumber;
                    }
                    currNumber = 0;
                    if(s[i] == ')') {
                        eval += lastNumber;
                        currNumber = eval;
                        lastOperation = number[stack.top()]; stack.pop();
                        lastNumber = stack.top(); stack.pop();
                        eval = stack.top(); stack.pop();
                    } else {
                        lastOperation = s[i];
                    }
                }
            }
        }

        return eval + lastNumber;
    }
};
