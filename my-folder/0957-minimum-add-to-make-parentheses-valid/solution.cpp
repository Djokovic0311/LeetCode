class Solution {
public:
    int minAddToMakeValid(string s) {
    int open = 0, close = 0;  // To keep track of unmatched open and close parentheses
    
    for(char c : s) {
        if(c == '(') {
            open++;
        } else if(open > 0) {
            open--;
        } else {
            close++;
        }
    }
    
    return open + close;  // Total moves required        
    }
};
