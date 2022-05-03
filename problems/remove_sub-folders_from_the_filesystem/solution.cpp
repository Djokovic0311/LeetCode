class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        
        for (auto s : folder) {
            if (res.size() == 0) {
                res.push_back(s);
                continue;
            }
            
            string parent = res[res.size()-1];
            if (s.substr(0, parent.size()+1) != parent+'/')
                res.push_back(s); 
        }
        
        return res;
    }
};