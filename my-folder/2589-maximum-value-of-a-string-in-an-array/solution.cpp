class Solution {
public:
    bool isvalid(string str) {
        for(char c : str) {
            if(!isdigit(c)) return false;
        }
        return true;
    }
    int maximumValue(vector<string>& strs) {
        int mx = 0;
        for(string str : strs) {
            if(isvalid(str)) {
                mx = max(mx, stoi(str));
            }
            else {
                mx = max(mx, int(str.length()));
            }
        }
        return mx;
    }
};
