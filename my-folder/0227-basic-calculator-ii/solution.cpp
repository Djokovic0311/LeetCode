class Solution {
public:
    int calculate(string s) {
        int curr = 0, last = 0;
        char sign = '+';
        s += '+';  // Append '+' to handle the last number
        int result = 0;

        for(int i = 0; i < s.length(); i++) {  // Use s.length() to include the appended '+'
            if(isdigit(s[i])) {
                curr = (curr * 10) + (s[i] - '0');
            } else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                if(sign == '+') {
                    result += last;
                    last = curr;
                } else if(sign == '-') {
                    result += last;
                    last = (-1) * curr;
                } else if(sign == '*') {
                    last = last * curr;
                } else if(sign == '/') {
                    last = last / curr; 
                }

                sign = s[i];
                curr = 0;
            }
        }

        return result + last;
    }
};
