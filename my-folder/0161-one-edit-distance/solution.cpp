class Solution {
public:
    bool isOneEditDistance(string s, string t) {
    int len_s = s.length();
    int len_t = t.length();
    
    // Ensure that s is shorter than t
    if (len_s > len_t) {
        return isOneEditDistance(t, s);
    }
    
    // If the lengths differ by more than 1 or strings are the same, return false
    if (len_t - len_s > 1 || s == t) {
        return false;
    }

    for (int i = 0; i < len_s; ++i) {
        if (s[i] != t[i]) {
            // If lengths are same, check replace operation
            if (len_s == len_t) {
                return s.substr(i + 1) == t.substr(i + 1);
            }
            // If s is shorter, check insert operation in s or delete operation in t
            return s.substr(i) == t.substr(i + 1);
        }
    }
    // Only reach here if the two strings have the same content with one extra character at the end of t.
    return true;        
    }
};
