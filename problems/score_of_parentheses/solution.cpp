class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        int score = 0;
        for(char c : s) {
            if(c == '(')
            {
                stk.push(score);
                score = 0;
            }
            else{
                    score = stk.top() + max(2 * score, 1);
                    stk.pop();
            }
            cout << score << ' ';
            // if(!stk.empty()) cout << stk.top();
        }
        return score;
    }
};