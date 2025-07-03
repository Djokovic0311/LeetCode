class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.length() < k) {
            string tmp = s;
            for(int i = 0; i < tmp.length(); i++) {
                tmp[i] = (tmp[i] - 'a' + 1) % 26 + 'a';
            }
            s += tmp;
        }
        return s[k-1];
    }
};
