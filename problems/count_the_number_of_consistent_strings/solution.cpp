class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> dic(26,0);
        for(char c : allowed) {
            dic[c-'a'] = 1;
        }
        int n = words.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            int j = 0;
            for(j = 0; j < words[i].size(); j++) if(dic[words[i][j]-'a'] == 0) break;
            if(j == words[i].size()) res++;
        }
        return res;
    }
};