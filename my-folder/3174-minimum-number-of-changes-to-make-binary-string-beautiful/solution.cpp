class Solution {
public:
    int minChanges(string s) {
    int n = s.size();
    int changes = 0;
    
    for (int i = 0; i < n; i += 2) {
            if (s[i] != s[i+1]) {
                // The current pair is either "01" or "10"
                changes++;
            }
        }

        return changes;        
    }
};
