class Solution {
public:
    bool canConvert(string str1, string str2) {
        unordered_map<char, char> mp;
        int n = str1.length();
        string tmp = "";
        if(str1 == str2) return true;
        for(int i = 0; i < n; i++) {
            if(mp.find(str1[i]) == mp.end()) {
                mp[str1[i]] = str2[i];
                tmp += str2[i];
            }
            else {
                tmp += mp[str1[i]];
            }    
            
        }
        set<char> st(tmp.begin(), tmp.end());
        if(st.size() == 26) return false;
        return tmp == str2;
    }
};