class Solution {
public:
    string interpret(string command) {
        int n = command.length();
        string res = "";
        for(int i = 0; i < n; i++) {
            if(command[i] == '(') {
                if(command[i+1] == 'a') {
                    res += "al";
                    i += 3;
                }
                else if(command[i+1] == ')') {
                    res += 'o';
                    i++;
                }
            }
            else res += command[i];
        }
        return res;
    }
};