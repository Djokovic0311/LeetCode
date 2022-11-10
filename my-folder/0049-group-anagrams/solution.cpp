class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(string s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(s);
        }
        for(auto it = mp.begin(); it != mp.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};
