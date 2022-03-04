class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        if(n == 1) return true;
        bool valid = true;
        for(int i = 1; i < n; i++) {
            if(valid == false && s[i] == '1') return false;
            if(s[i] == '0') valid = false;
            
        }
        return true;
    }
};