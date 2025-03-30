class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last_pos[26] = {0};
        int n = s.length();
        vector<int> res;
        int len = 0;
        int min_pos = -1;

        for(int i = 0; i < n; i++) {
            last_pos[s[i]-'a'] = i;
        }
        
        for(int i = 0; i < n; i++) {
            int lp = last_pos[s[i]-'a'];
            min_pos = max(min_pos, lp);
            len++;
            if(i == min_pos) {
                res.push_back(len);
                len = 0;
                min_pos = -1;
            }
        }
        return res;
    }
};
