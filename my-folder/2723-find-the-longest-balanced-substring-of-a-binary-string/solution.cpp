class Solution {
public:
    bool isvalid(string s) {
        int l = s.length();
        if(l % 2 != 0) return false;
        int i = 0, j = l-1;
        
        while(i < j) {
            // cout << s << endl;
            // cout << i << " " << j << endl;
            if(s[i] == '0' &&s[j] == '1') {
                i++;
                j--;
            }
            else return false;
        }
        return true;
        
    }
    int findTheLongestBalancedSubstring(string s) {
        int l = s.length();
        int res = 0;
        for(int i = 0; i < l; i++) {
            for(int j = i+1; j < l; j++) {
                if(isvalid(s.substr(i,j-i+1)))
                    res = max(res, j-i+1);
            }
        }
        
        return res;
    }
};
