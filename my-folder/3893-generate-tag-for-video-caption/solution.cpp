class Solution {
public:
    string generateTag(string caption) {
        string res = "#";
        int n = caption.length();
        int idx = 0;
        while(caption[idx] == ' ') idx++;
        while(res.length()<100 && idx < n) {
            if(idx > 0 && caption[idx-1] == ' ' && res.length()!= 1) {
                res += toupper(caption[idx]);
            } else {
                res += tolower(caption[idx]);
            }
            idx++;
            while(caption[idx] == ' ') idx++;
        }
        return res;
    }
};
