class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        int n = queries.size();
        int l = pattern.length();

        for(int i = 0; i < n; i++) {
            string s = queries[i];
            int j = 0;
            int x;
            for (x = 0; x < s.length(); x++) {
                char c = s[x];
                if (j < pattern.length() && c == pattern[j]) j++;
                else if (c < 'a')  {
                    res.push_back(false);
                    break;
                }                
            }
            if(x == s.length())
                res.push_back(j == pattern.length());
        }
        return res;
    }
};
