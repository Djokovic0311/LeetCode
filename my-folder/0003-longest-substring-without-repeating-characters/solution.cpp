class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int n = s.length();
        string tmp = "";
        int res = 0;
        for(int i = 0; i < n; i++) {
            tmp += s[i];
            if(st.find(s[i]) == st.end()) {
                st.insert(s[i]);
                res = max(res,int(tmp.length()) );
            }
            else {
                int newStart = tmp.find(s[i]) + 1;
                tmp = string(tmp.begin()+newStart, tmp.end());
                
                st = unordered_set(tmp.begin(), tmp.end());
            }
        }
        return res;
    }
};
