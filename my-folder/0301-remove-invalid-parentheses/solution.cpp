class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        unordered_set<string> visited;
        vector<string> res;
        
        for (q.push(s); !q.empty(); q.pop()) {
            s = q.front();
            if (isValid(s)) res.push_back(s);
            
            if (!res.empty()) continue;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != '(' and s[i] != ')') continue;
                auto ss(s); ss.erase(i, 1);
                if (visited.insert(ss).second) q.push(ss);
            }
        }
        return res;
    }
    
    bool isValid(string s) { // if s is valid to pair parentheses
        int counter = 0;
        for (char c : s) {
            if (c == '(') ++counter;
            else if (c == ')') --counter;
            if (counter < 0) return false;
        }
        return counter == 0;
    }
};
