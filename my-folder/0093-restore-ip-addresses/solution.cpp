class Solution {
public:
    vector<string> res;
    string solution;
    void backtracking(string s, int start, int part) {
        if(part == 4 && s.size() == start) {
            res.push_back(solution);
        }
        for(int i = start; i < s.size(); i++) {
            if(part < 4 && i - start <3 && isvalid(s, start, i)) {
                solution.append(s.substr(start, i-start+1));
                part++;
                if(part < 4)
                    solution.push_back('.');
                backtracking(s, i+1, part);
                if(part < 4) solution.pop_back();
                part--;
                for(int j = 0; j < i-start+1; j++) solution.pop_back();
            }
        }
    }
    bool isvalid(string s, int start, int end) {
        string tmp = s.substr(start, end-start+1);
        int ip = stoi(tmp);
        if(s[start] == '0' && start != end) return false;
        //self explanatory
        else if(ip >= 0 && ip <= 255) return true;
        
        //eg: 256
        return false;        
    }
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0);
        return res;
    }
};
