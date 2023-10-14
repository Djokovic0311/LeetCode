class Solution {
public:
    int minInsertions(string s) {
        int open = 0, ans = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                open++;
            } else {
                if (i < n - 1 && s[i + 1] == ')') {
                    // If it's a "))"
                    if (open > 0) {
                        open--;
                    } else {
                        ans++;  // Insert an '(' before this pair.
                    }
                    i++;  // Skip next ')'.
                } else {
                    // If it's a lone ')'
                    if (open > 0) {
                        open--;
                        ans++;  // Insert a ')' after this.
                    } else {
                        ans += 2;  // Insert both '(' before and ')' after this.
                    }
                }
            }
        }
        ans += open * 2;  // Every unmatched '(' needs 2 characters.
        return ans;        
    }
};
