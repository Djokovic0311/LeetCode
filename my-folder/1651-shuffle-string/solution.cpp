class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.length();
        vector<char> res(n);
        for(int i = 0; i < n; i++) {
            res[indices[i]] = s[i];
        }
        string str = "";
        for(char c: res) {
            str += c;
            
        }
        return str;
    }
};
