class Solution {
public:
    int takeCharacters(string s, int k) {
        int cnt1 = k, cnt2 = k, cnt3 = k;
        string str = s+s;
        int res = INT_MAX;
        
        int n = str.length();
        int i = 0, j = 0;
        if(k == 0) return 0;
        while(i < n && j < n) {
            while(cnt1 <= 0 && cnt2 <= 0 && cnt3 <= 0) {
                
                // cout << cnt1 << ' ' << cnt2 << ' ' << cnt3 << endl;
                if(j >= n/2 && i <= n/2) {
                    // cout << i << ' ' << j << endl;
                    res = min(res, j-i);
                }
                    
                if(str[i] == 'a' && cnt1 < 0) {
                    cnt1++;
                    i++;
                }
                else if(str[i] == 'b' && cnt2 < 0){
                    cnt2++;
                    i++;
                }
                else if(str[i] == 'c' && cnt3 < 0){
                    cnt3++;
                    i++;
                }
                else break;
                
            }
            // cout << j << endl;
            if(str[j] == 'a'){
                cnt1--;
                j++;
            }
            else if(str[j] == 'b'){
                cnt2--;
                j++;
            }
            else {
                // cout << cnt1 << ' ' << cnt2 << ' ' << cnt3 << endl;
                cnt3--;
                j++;
            }
        }
        return res > n/2?-1:res;
    }
};
