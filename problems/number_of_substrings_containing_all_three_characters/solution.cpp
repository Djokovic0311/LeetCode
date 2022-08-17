class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int cnt = 0;
        int i = 0, j = 0;
        int count[3] = {0,0,0};
        for(j = 0; j < n; j++) {
            count[s[j]-'a']++;
            while(count[0] && count[1] && count[2]) {
                // cnt++;
                count[s[i++]-'a']--;
                
            }
            cout << i << endl;
            cnt += i;
        }
        return cnt;
    }
};