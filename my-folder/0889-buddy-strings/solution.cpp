class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()) return false;
        int diff1 = -1, diff2 = -1;
        unordered_set<char> A_letters;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                if (diff1 == -1)
                    diff1 = i;
                else if (diff2 == -1)
                    diff2 = i;
                else
                    return false; 
            }
            A_letters.insert(s[i]);
        }
        if (diff1 != -1 && diff2 != -1) 
            return s[diff1] == goal[diff2] && s[diff2] == goal[diff1]; 
        if (diff1 != -1) 
            return false;
        return A_letters.size() < s.size(); 
    }
};
