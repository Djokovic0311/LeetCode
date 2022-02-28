class Solution {
public:
    string removeOuterParentheses(string S) {
        int count = 0;
        std::string str;
        for (char c : S) {
            if (c == '(') {
                if (count++) {
                    str += '(';
                }
            } else {
                if (--count) {
                    str += ')';
                }
            }
            
            // cout << str < endl;
        }
        return str;        
    }
};