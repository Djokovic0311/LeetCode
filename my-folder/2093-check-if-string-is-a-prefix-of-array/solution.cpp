class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n = words.size();
        string res = "";
        int i = 0;
        while(i < n && res != s) {
            res += words[i];
            i++;
        }
        if(res == s) return true;
        else return false;
    }
};
