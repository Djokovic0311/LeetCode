class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string tmp;
        string res = "";
        int count = 0;
        while(ss>> tmp && count < k) {
            count++;
            res += tmp;
            if(count < k) res += ' ';
        }
        return res;
    }
};