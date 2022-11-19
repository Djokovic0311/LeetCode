class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool comment = false;
        int n = source.size();
        string s;

        for(int i = 0; i < source.size(); i++) {
            for(int j = 0; j < source[i].size(); j++) {
                if(!comment && j + 1 < source[i].size() && source[i][j] == '/' && source[i][j+1]=='/') break;
                else if(!comment && j + 1 < source[i].size() && source[i][j] == '/' && source[i][j+1]=='*') comment = true, j++;
                else if(comment && j + 1 < source[i].size() && source[i][j] == '*' && source[i][j+1]=='/') comment = false, j++;
                else if(!comment) s.push_back(source[i][j]);
            }
            
            if(!comment && s.size()) res.push_back(s), s.clear();
        }
        return res;

    }
};