class Solution {
public:
    string generateTheString(int n) {
        
        if(n % 2 == 1) {string s(n,'a'); return s;}
        else {
            string s1(n-1,'a');
            string s2(1,'b');
            return s1 + s2;
        }
    }
};