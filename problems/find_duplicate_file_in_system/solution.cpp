class Solution {
public:
    int position(string str, int index, char symbole, string &res) {
        res = "";
        while(index < str.size() && str[index] != symbole) {
            res += str[index];
            index++;
        }
        return ++index;
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(string s: paths) {
            string root = "";
            int pos = position(s, 0, ' ', root);
            while(pos < s.size()) {
                string subroot = "", file = "";
                pos = position(s, pos, '(', subroot);
                pos = position(s, pos, ')', file);
                mp[file].push_back(root + "/" + subroot);
                pos++;
            }
        }
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if((it->second).size() > 1)
                res.push_back(it->second);
        }
        return res;
    }
};