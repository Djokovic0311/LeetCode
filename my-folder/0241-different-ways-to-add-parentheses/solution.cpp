class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                // Split the string around the operator
                vector<int> leftResults = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightResults = diffWaysToCompute(expression.substr(i+1));
                
                for (int left : leftResults) {
                    for (int right : rightResults) {
                        switch (c) {
                            case '+':
                                result.push_back(left + right);
                                break;
                            case '-':
                                result.push_back(left - right);
                                break;
                            case '*':
                                result.push_back(left * right);
                                break;
                        }
                    }
                }
            }
        }

        // If there were no operators, the result is simply the number itself
        if (result.empty()) {
            result.push_back(stoi(expression));
        }
        return result;
    }
};
