class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int cnt = 0;
        for(char c : s) {
            if(c=='1')
                cnt++;
        }
        int cnt1 = cnt;
        int n = s.length();
        bool left = true, right = true;
        
        for(int i = 0; i < n; i++) {
            // cout << i << endl;
            // cout << cnt << endl;
            
            if(s[i]!= target[i]) {
                if(s[i] == '0') {
                    if(cnt < 1) left = false;
                    cnt++;
                }
                else {
                    
                    if(cnt < 2) left = false;
                    cnt--;
                }
            }
        }
        cnt = cnt1;
        for(int i = n-1; i >= 0; i--) {
            // cout << i << endl;
            // cout << cnt << endl;
            
            if(s[i]!= target[i]) {
                if(s[i] == '0') {
                    if(cnt < 1) right = false;
                    cnt++;
                }
                else {
                    
                    if(cnt < 2) right = false;
                    cnt--;
                }
            }
        }
        // cout << left << ' ' << right << endl;
        return left||right;
    }
};
