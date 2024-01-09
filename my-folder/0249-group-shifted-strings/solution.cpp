class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        for(string s : strings) {
            int start = s[0]-'a';
            string tmp = s;
            for(int i = 0; i < tmp.length(); i++) {
                tmp[i] -= start;
                if(tmp[i] < 'a') tmp[i] = 'z' -('a'-tmp[i]-1);
            }
            mp[tmp].push_back(s);
        }

        for(auto it : mp) {
            res.push_back(it.second);
        }

        return res;
    }
};
