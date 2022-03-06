class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> res;
        string begin = s.substr(0,2);
        string end = s.substr(3,2);
        for(char c = begin[0]; c <= end[0]; c++) {
            for(char r = begin[1]; r <= end[1]; r++) {
                // cout <<  r <<endl;
                string tmp = "";
                tmp += c;
                tmp += r;
                res.push_back(tmp);
            }
        }
        return res;
    }
};